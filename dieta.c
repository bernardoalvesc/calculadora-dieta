#include <stdio.h>

int main() {
    char genero;
    float peso, altura, tmb, get, caloriasNecessarias;
    int idade;
    int nivelAtividade;
    float fatorAtividade;
    int objetivo;

    // Entrada de dados
    printf("Digite seu genero (M para masculino, F para feminino): ");
    scanf(" %c", &genero);
    
    printf("Digite seu peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura (em cm): ");
    scanf("%f", &altura);

    printf("Digite sua idade (em anos): ");
    scanf("%d", &idade);

    // Calculo da TMB
    if (genero == 'M' || genero == 'm') {
        tmb = 88.362 + (13.397 * peso) + (4.799 * altura) - (5.677 * idade);
    } else if (genero == 'F' || genero == 'f') {
        tmb = 447.593 + (9.247 * peso) + (3.098 * altura) - (4.330 * idade);
    } else {
        printf("Genero invalido!\n");
        return 1;
    }

    // Exibe a TMB
    printf("Sua TMB e: %.2f calorias\n", tmb);

    // Selecao do nivel de atividade fisica
    printf("\nSelecione seu nivel de atividade fisica:\n");
    printf("1. Sedentario (pouco ou nenhum exercicio)\n");
    printf("2. Levemente ativo (exercicio leve ou esporadico)\n");
    printf("3. Moderadamente ativo (exercicio moderado regular)\n");
    printf("4. Muito ativo (exercicio intenso ou atividade fisica extenuante)\n");
    printf("5. Super ativo (atleta de alto desempenho ou trabalho fisico pesado)\n");
    scanf("%d", &nivelAtividade);

    switch (nivelAtividade) {
        case 1:
            fatorAtividade = 1.2;
            break;
        case 2:
            fatorAtividade = 1.375;
            break;
        case 3:
            fatorAtividade = 1.55;
            break;
        case 4:
            fatorAtividade = 1.725;
            break;
        case 5:
            fatorAtividade = 1.9;
            break;
        default:
            printf("Nivel de atividade invalido!\n");
            return 1;
    }

    // Calculo do GET
    get = tmb * fatorAtividade;

    // Exibe o GET
    printf("Seu GET e: %.2f calorias\n", get);

    // Selecao de objetivo
    printf("\nSelecione seu objetivo:\n");
    printf("1. Manter o peso\n");
    printf("2. Perder peso\n");
    printf("3. Ganhar peso\n");
    printf("Digite o numero correspondente ao seu objetivo: ");
    scanf("%d", &objetivo);

    // Calculo das calorias necessarias para o objetivo
    switch (objetivo) {
        case 1:
            caloriasNecessarias = get;
            break;
        case 2:
            caloriasNecessarias = get - 300;
            break;
        case 3:
            caloriasNecessarias = get + 300;
            break;
        default:
            printf("Objetivo invalido!\n");
            return 1;
    }

    // Exibe as calorias necessarias
    printf("\nVoce deve consumir %.2f calorias por dia para atingir seu objetivo.\n", caloriasNecessarias);

    // Pausa para manter o programa aberto
    printf("\nPressione Enter para sair...");
    getchar();  // Captura o Enter do último scanf
    getchar();  // Aguarda novo Enter do usuário para encerrar

    return 0;
}

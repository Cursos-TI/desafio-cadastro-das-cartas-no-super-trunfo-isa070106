#include <stdio.h>

typedef struct {
    char nome[50];
    int estado;
    int codigo;
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade_populacional(unsigned long int populacao, float area) {
    if (area != 0) {
        return populacao / area;
    }
    return 0;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    if (populacao != 0) {
        return pib / populacao;
    }
    return 0;
}

// Função para calcular o Super Poder
float calcular_super_poder(Carta c) {
    // Somando os atributos numéricos, considerando o inverso da densidade populacional
    float inverso_densidade = 1 / c.densidade_populacional;
    return c.populacao + c.area + c.pib + c.pontos_turisticos + c.pib_per_capita + inverso_densidade;
}

// Função para comparar dois atributos e determinar o vencedor
int comparar_atributo(float a, float b, int inverso) {
    if (inverso == 1) {
        // Para atributos que o menor valor vence (densidade populacional)
        if (a < b) return 1;  // Carta 1 vence
        return 0;              // Carta 2 vence
    } else {
        // Para os demais atributos (maior valor vence)
        if (a > b) return 1;  // Carta 1 vence
        return 0;              // Carta 2 vence
    }
}

int main() {
    Carta carta1, carta2;

    // Entrada para a Carta 1
    printf("Digite os dados da Carta 1:\n");

    // Nome da carta 1
    printf("Nome: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[scanf(carta1.nome, "\n")] = '\0';  // Remove a nova linha que vem com fgets

    // Estado da carta 1
    printf("Estado: ");
    scanf("%d", &carta1.estado);

    // Código da carta 1
    printf("Codigo: ");
    scanf("%d", &carta1.codigo);

    // População da carta 1
    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    // Área da carta 1
    printf("Area: ");
    scanf("%f", &carta1.area);

    // PIB da carta 1
    printf("PIB: ");
    scanf("%f", &carta1.pib);

    // Pontos Turísticos da carta 1
    printf("Pontos Turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Calculando atributos da Carta 1
    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta1.super_poder = calcular_super_poder(carta1);

    getchar(); // Limpar o buffer do teclado (para o próximo fgets)

    // Entrada para a Carta 2
    printf("\nDigite os dados da Carta 2:\n");

    // Nome da carta 2
    printf("Nome: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = '\0';  // Remove a nova linha que vem com fgets

    // Estado da carta 2
    printf("Estado: ");
    scanf("%d", &carta2.estado);

    // Código da carta 2
    printf("Codigo: ");
    scanf("%d", &carta2.codigo);

    // População da carta 2
    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    // Área da carta 2
    printf("Area: ");
    scanf("%f", &carta2.area);

    // PIB da carta 2
    printf("PIB: ");
    scanf("%f", &carta2.pib);

    // Pontos Turísticos da carta 2
    printf("Pontos Turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Calculando atributos da Carta 2
    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);
    carta2.super_poder = calcular_super_poder(carta2);

    // Exibindo os resultados das comparações
    printf("\nComparacao de Cartas:\n");

    // Comparação de População
    printf("Populacao: Carta 1 venceu (%d)\n", comparar_atributo(carta1.populacao, carta2.populacao, 0));

    // Comparação de Área
    printf("Area: Carta 1 venceu (%d)\n", comparar_atributo(carta1.area, carta2.area, 0));

    // Comparação de PIB
    printf("PIB: Carta 1 venceu (%d)\n", comparar_atributo(carta1.pib, carta2.pib, 0));

    // Comparação de Pontos Turísticos
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", comparar_atributo(carta1.pontos_turisticos, carta2.pontos_turisticos, 0));

    // Comparação de Densidade Populacional (menor valor vence)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", comparar_atributo(carta1.densidade_populacional, carta2.densidade_populacional, 1));

    // Comparação de PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", comparar_atributo(carta1.pib_per_capita, carta2.pib_per_capita, 0));

    // Comparação de Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", comparar_atributo(carta1.super_poder, carta2.super_poder, 0));

    return 0;
}
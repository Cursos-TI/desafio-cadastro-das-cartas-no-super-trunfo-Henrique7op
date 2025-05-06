#include <stdio.h>
#include <string.h>

int main(){

    print("desafio super trunfo! /n");
}
// Define a structure to represent a city card
typedef struct {
    char estado[10];
    char codigo[10];
    char nome[50];
    long populacao;
    double area;
    double pib;
    int pontos_turisticos;
} CityCard;

// Function to compare two cities based on the selected attribute
CityCard compare_cities(CityCard city1, CityCard city2, int attribute) {
    // Use an array to store the comparison results
    int comparison_results[] = {
        city1.populacao > city2.populacao,  // Attribute 1: Population
        city1.area > city2.area,            // Attribute 2: Area
        city1.pib > city2.pib,              // Attribute 3: GDP
        city1.pontos_turisticos > city2.pontos_turisticos // Attribute 4: Tourist Attractions
    };

    // Use the attribute choice as an index to determine the winner
    // If the comparison result is 1, city1 wins; otherwise, city2 wins
    return comparison_results[attribute - 1] ? city1 : city2;
}

int main() {
    // Create the city cards
    CityCard sao_paulo = {"A", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    CityCard rio_de_janeiro = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    int choice;
    printf("Bem-vindo ao jogo de comparação de cidades!\n");
    printf("Escolha uma característica para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("Digite o número da característica (1-4): ");
    scanf("%d", &choice);

    // Validate the input
    if (choice < 1 || choice > 4) {
        printf("Escolha inválida. Tente novamente.\n");
        return 1;
    }

    // Compare the cities based on the selected attribute
    CityCard winner = compare_cities(sao_paulo, rio_de_janeiro, choice);

    // Display the results
    printf("\nCarta 1: %s (%s) - População: %ld, Área: %.2f km², PIB: %.2f bilhões, Pontos Turísticos: %d\n",
           sao_paulo.nome, sao_paulo.estado, sao_paulo.populacao, sao_paulo.area, sao_paulo.pib, sao_paulo.pontos_turisticos);
    printf("Carta 2: %s (%s) - População: %ld, Área: %.2f km², PIB: %.2f bilhões, Pontos Turísticos: %d\n",
           rio_de_janeiro.nome, rio_de_janeiro.estado, rio_de_janeiro.populacao, rio_de_janeiro.area, rio_de_janeiro.pib, rio_de_janeiro.pontos_turisticos);
    printf("\nA cidade vencedora é: %s!\n", winner.nome);

    return 0;
}
#include <stdio.h>
#include <string.h>

// Define a structure to represent a city card
typedef struct {
    char estado[10];
    char codigo[10];
    char nome[50];
    long populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double pib_per_capita;
    double densidade_pop;
} CityCard;

// Function to compare two cities based on the selected attribute
CityCard compare_cities(CityCard city1, CityCard city2, int attribute) {
    // Use an array to store the comparison results
    int comparison_results[] = {
        city1.populacao > city2.populacao,
        city1.area > city2.area,
        city1.pib > city2.pib,
        city1.pontos_turisticos > city2.pontos_turisticos,
        city1.pib_per_capita > city2.pib_per_capita,
        city1.densidade_pop > city2.densidade_pop
    };

    // Array de mensagens de erro correspondentes a cada atributo
    char* error_messages[] = {
        "População",
        "Área",
        "PIB",
        "Pontos Turísticos",
        "PIB per capita",
        "Densidade populacional"
    };

    // Validar a escolha usando operador ternário e array de mensagens
    int valid_choice = (choice > 0 && choice < 7);
    printf("%s", valid_choice ? "" : "Escolha inválida. Use um número entre 1 e 6.\n");

    // Retornar cidade vencedora ou uma cidade vazia se escolha inválida
    return valid_choice ? (comparison_results[attribute - 1] ? city1 : city2) : (CityCard){0};
}

int main() {
    // Create the city cards
    CityCard sao_paulo = {"A", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    CityCard rio_de_janeiro = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};
    
    // Calcular PIB per capita e densidade populacional
    sao_paulo.pib_per_capita = sao_paulo.pib * 1e9 / sao_paulo.populacao;
    sao_paulo.densidade_pop = sao_paulo.populacao / sao_paulo.area;
    
    rio_de_janeiro.pib_per_capita = rio_de_janeiro.pib * 1e9 / rio_de_janeiro.populacao;
    rio_de_janeiro.densidade_pop = rio_de_janeiro.populacao / rio_de_janeiro.area;

    int choice;
    printf("Bem-vindo ao jogo de comparação de cidades!\n");
    printf("Escolha uma característica para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. PIB per capita\n");
    printf("6. Densidade populacional\n");
    printf("Digite o número da característica (1-6): ");
    scanf("%d", &choice);

    // Compare the cities based on the selected attribute
    CityCard winner = compare_cities(sao_paulo, rio_de_janeiro, choice);

    // Mostrar resultados apenas se a escolha foi válida
    printf("%s", winner.nome[0] ? "\n" : ""); // Pula linha apenas se houver vencedor
    
    // Mostrar detalhes das cidades usando operador ternário para verificar escolha válida
    printf("%s", winner.nome[0] ? "Carta 1: São Paulo (A)\n" : "");
    printf("%s", winner.nome[0] ? "- População: 12325000\n" : "");
    printf("%s", winner.nome[0] ? "- Área: 1521.11 km²\n" : "");
    printf("%s", winner.nome[0] ? "- PIB: 699.28 bilhões\n" : "");
    printf("%s", winner.nome[0] ? "- Pontos Turísticos: 50\n" : "");
    printf("%s", winner.nome[0] ? "- PIB per capita: 56695.74\n" : "");
    printf("%s", winner.nome[0] ? "- Densidade populacional: 8102.61 hab/km²\n\n" : "");
    
    printf("%s", winner.nome[0] ? "Carta 2: Rio de Janeiro (B)\n" : "");
    printf("%s", winner.nome[0] ? "- População: 6748000\n" : "");
    printf("%s", winner.nome[0] ? "- Área: 1200.25 km²\n" : "");
    printf("%s", winner.nome[0] ? "- PIB: 300.50 bilhões\n" : "");
    printf("%s", winner.nome[0] ? "- Pontos Turísticos: 30\n" : "");
    printf("%s", winner.nome[0] ? "- PIB per capita: 44531.27\n" : "");
    printf("%s", winner.nome[0] ? "- Densidade populacional: 5621.74 hab/km²\n\n" : "");
    
    printf("%s", winner.nome[0] ? "A cidade vencedora é: " : "");
    printf("%s%s", winner.nome, winner.nome[0] ? "!\n" : "");

    return winner.nome[0] ? 0 : 1; // Retorna 0 se sucesso, 1 se escolha inválida
}
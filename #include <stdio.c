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
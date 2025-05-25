#include <stdio.h>
#include <string.h>

//estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int densidade;
    int pib;
} Carta;

// atributos disponiveis
void mostrarAtributosDisponiveis(int escolhido) {
    if (escolhido != 1) printf("1. Populacao\n");
    if (escolhido != 2) printf("2. Area\n");
    if (escolhido != 3) printf("3. Densidade Demografica\n");
    if (escolhido != 4) printf("4. PIB\n");
}

// atributos escolhiddos
int obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.densidade;
        case 4: return carta.pib;
        default: return -1;
    }
}

//nomes do stributos
const char* nomeDoAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "Densidade Demografica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

//funçao principal
int main() {
    //cartas 
    Carta carta1 = {"Brasil", 213, 8516, 25, 1600};
    Carta carta2 = {"Canada", 38, 9984, 4, 1800};

    int escolha1, escolha2;
    int valor1_carta1, valor2_carta1, valor1_carta2, valor2_carta2;

    printf("Bem-vindo ao Super Trunfo - Desafio Mestre!\n\n");

    //primeiro atribbuto
    printf("Escolha o primeiro atributo para comparacao:\n");
    printf("1. Populacao\n2. Area\n3. Densidade Demografica\n4. PIB\n");
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1: case 2: case 3: case 4:
            break;
        default:
            printf("Opcao invalida. Encerrando.\n");
            return 1;
    }

    //segundo atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    mostrarAtributosDisponiveis(escolha1);
    scanf("%d", &escolha2);

    if (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 4) {
        printf("Opcao invalida ou repetida. Encerrando.\n");
        return 1;
    }

    // valores do atributo
    valor1_carta1 = obterValorAtributo(carta1, escolha1);
    valor2_carta1 = obterValorAtributo(carta1, escolha2);
    valor1_carta2 = obterValorAtributo(carta2, escolha1);
    valor2_carta2 = obterValorAtributo(carta2, escolha2);

    // comparaçao de menor ou maior
    int ponto1 = 0, ponto2 = 0;

    ponto1 += (escolha1 == 3) ? (valor1_carta1 < valor1_carta2) : (valor1_carta1 > valor1_carta2);
    ponto2 += (escolha1 == 3) ? (valor1_carta2 < valor1_carta1) : (valor1_carta2 > valor1_carta1);

    ponto1 += (escolha2 == 3) ? (valor2_carta1 < valor2_carta2) : (valor2_carta1 > valor2_carta2);
    ponto2 += (escolha2 == 3) ? (valor2_carta2 < valor2_carta1) : (valor2_carta2 > valor2_carta1);

    //soma
    int soma_carta1 = valor1_carta1 + valor2_carta1;
    int soma_carta2 = valor1_carta2 + valor2_carta2;

    //resultado
    printf("\n---------------- RESULTADO ----------------\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n", carta2.nome);
    printf("\nComparando os atributos:\n");
    printf("- %s: %d (C1) x %d (C2)\n", nomeDoAtributo(escolha1), valor1_carta1, valor1_carta2);
    printf("- %s: %d (C1) x %d (C2)\n", nomeDoAtributo(escolha2), valor2_carta1, valor2_carta2);
    printf("\nSoma dos atributos:\n");
    printf("- %s: %d\n", carta1.nome, soma_carta1);
    printf("- %s: %d\n", carta2.nome, soma_carta2);

    //finaal
    printf("\nResultado Final: ");
    printf((soma_carta1 > soma_carta2) ? "%s venceu!\n" :
           (soma_carta2 > soma_carta1) ? "%s venceu!\n" :
           "Empate!\n", (soma_carta1 > soma_carta2) ? carta1.nome : carta2.nome);

    return 0;
}

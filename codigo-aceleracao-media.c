#include <stdio.h>
#include <math.h>

void receberDados (int quantidade, double valores[]) {
    for (int i = 0; i < quantidade; i++) {
        printf ("%d - ", i+1);
        scanf ("%lf", &valores[i]);
    }
}

double calcularSomaTotal (int quantidade, double valores[]) {
    double somaInstancia, soma = 0.0;
    for (int i = 0; i < quantidade; i++) {
            valores[quantidade] += valores[i];
        }
        valores[quantidade] /= quantidade;

    for (int i = 0; i < quantidade; i++) {
            somaInstancia = (valores[i] - valores[quantidade]) * (valores[i] - valores[quantidade]);
            soma += somaInstancia;
        }
    soma *= (1.0/(quantidade - 1.0));
    return soma;
}

int main () {
    int quantidadeMedidas;

    printf ("Insira a quantidade de medidas:\n");
    scanf ("%d", &quantidadeMedidas);

    double valoresMedidas[quantidadeMedidas + 1];

    printf ("Insira o valor das medidas:\n");

    receberDados (quantidadeMedidas, valoresMedidas);

    double desvioPadrao = sqrt (calcularSomaTotal(quantidadeMedidas, valoresMedidas));
    double erroDesvioPadrao = desvioPadrao / sqrt (quantidadeMedidas);
    double erroTotal = sqrt ((0.001*0.001)+(erroDesvioPadrao));
    double aceleracaoMedia = (2.0*0.1) / (valoresMedidas[quantidadeMedidas]*valoresMedidas[quantidadeMedidas]);
    double erroValoresMedidas = (valoresMedidas[quantidadeMedidas]*valoresMedidas[quantidadeMedidas])*((erroTotal/valoresMedidas[quantidadeMedidas])+(erroTotal/valoresMedidas[quantidadeMedidas]));
    double erroAceleracao = (0.1*(valoresMedidas[quantidadeMedidas]*valoresMedidas[quantidadeMedidas]))*((0.0005/0.1)+(erroValoresMedidas/(valoresMedidas[quantidadeMedidas]*valoresMedidas[quantidadeMedidas])));

    printf ("Tempo Médio: %.3lf±%.3lf\n", valoresMedidas[quantidadeMedidas], erroTotal);
    printf ("Aceleração Média: %.3lf±%.3lf\n", aceleracaoMedia, erroAceleracao);

    return 0;
}

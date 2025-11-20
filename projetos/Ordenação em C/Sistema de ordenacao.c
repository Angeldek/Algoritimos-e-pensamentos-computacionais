#include <stdio.h> // inclusão da biblioteca padrão de entrada e saída
#include <stdlib.h> // inclusão da biblioteca padrão para funções utilitárias
#include <time.h> // inclusão da biblioteca para manipulação de tempo

// Função de ordenação Insertion Sort com contadores
void insertionSort(int arr[], int n, int *trocas, int *comp) { // função que ordena um array usando o algoritmo Insertion Sort
    for (int i = 1; i < n; i++) { // percorre o array a partir do segundo elemento
        int chave = arr[i]; // elemento chave a ser inserido na posição correta
        int j = i - 1; // índice do elemento anterior ao chave

        (*comp)++; // Primeira comparação
        while (j >= 0 && arr[j] > chave) { // enquanto o elemento anterior for maior que a chave
            arr[j + 1] = arr[j]; //     move o elemento maior para a direita
            j--; // decrementa o índice
            (*trocas)++; // conta a troca
            if (j >= 0) (*comp)++; // Comparações subsequentes
        }
        arr[j + 1] = chave; // insere a chave na posição correta
    }
}

// Função de ordenação Bubble Sort com contadores
void bubble_sort(int arr[], int n, int *trocas, int *comp) { // função que ordena um array usando o algoritmo Bubble Sort
    int i, j, aux; //   declaração de variáveis auxiliares
    for (j = 0; j < n - 1; j++) { // contador vai de 0 até o penúltimo item já colocado na posição correta
        for (i = 0; i < n - j - 1; i++) { // começa em 0 até o penúltimo array
            (*comp)++; // conta a comparação
            if (arr[i] > arr[i + 1]) { // se o elemento na posição i for maior que o próximo elemento
                aux = arr[i]; // guarda o valor de arr[i] em aux
                arr[i] = arr[i + 1]; // troca arr[i] com arr[i + 1]
                arr[i + 1] = aux; // coloca o valor de aux em arr[i + 1]
                (*trocas)++; // conta a troca
            }
        }
    }
}

// Função auxiliar para particionar o vetor no Quick Sort
int particiona(int arr[], int baixo, int alto, int *trocas, int *comp) { // função que particiona o array para o Quick Sort
    int pivo = arr[alto]; //    escolhe o último elemento como pivô
    int i = baixo - 1; // índice do menor elemento

    for (int j = baixo; j < alto; j++) { // percorre o array do índice baixo até o alto - 1
        (*comp)++; // conta a comparação
        if (arr[j] < pivo) { // se o elemento atual for menor que o pivô
            i++; // incrementa o índice do menor elemento
            int temp = arr[i]; // troca arr[i] com arr[j]
            arr[i] = arr[j]; // arr[j] com arr[i]
            arr[j] = temp; //  coloca o valor temporário em arr[j]
            (*trocas)++; // conta a troca
        }
    }

    int temp = arr[i + 1]; // coloca o pivô na posição correta
    arr[i + 1] = arr[alto]; // arr[alto] com arr[i+1]
    arr[alto] = temp; // valor temporário em arr[alto]
    (*trocas)++; // conta a troca

    return i + 1; // retorna o índice do pivô
}

// Função de ordenação Quick Sort com contadores
void quickSort(int arr[], int baixo, int alto, int *trocas, int *comp) { // função que ordena um array usando o algoritmo Quick Sort
    if (baixo < alto) { // condição de parada
        int pi = particiona(arr, baixo, alto, trocas, comp); // particiona o array  
        quickSort(arr, baixo, pi - 1, trocas, comp); // ordena a parte esquerda do pivô 
        quickSort(arr, pi + 1, alto, trocas, comp); //  ordena a parte direita do pivô
    }
}

// Função para imprimir o vetor
void imprimirArray(int arr[], int n) { // função que imprime os elementos de um array
    for (int i = 0; i < n; i++) // percorre o array
        printf("%d ", arr[i]); // imprime cada elemento seguido de um espaço
    printf("\n"); // nova linha após imprimir todos os elementos
}

// Função principal
int main() {
    int vetorOriginal[] = {4, 6, 0, 6, 2, 3, 5, 1}; // vetor original a ser ordenado
    int tamanho = sizeof(vetorOriginal) / sizeof(vetorOriginal[0]); //  calcula o tamanho do vetor

    int vetor1[tamanho], vetor2[tamanho], vetor3[tamanho];// vetores para cada algoritmo de ordenação
    int trocas = 0, comp = 0; //    contadores de trocas e comparações

    // Copiando os dados para cada vetor
    for (int i = 0; i < tamanho; i++) { // copia os elementos do vetor original para os três vetores
        vetor1[i] = vetorOriginal[i]; // vetor para Insertion Sort
        vetor2[i] = vetorOriginal[i]; // vetor para Bubble Sort
        vetor3[i] = vetorOriginal[i]; // vetor para Quick Sort
    }

    printf("Antes da ordenação:\n"); // imprime o vetor original antes da ordenação
    imprimirArray(vetorOriginal, tamanho); // imprime o vetor original

    // Insertion Sort
    trocas = comp = 0; // resetando os contadores
    insertionSort(vetor1, tamanho, &trocas, &comp); // chama a função de Insertion Sort
    printf("\nOrdenação com Insertion Sort:\n"); // imprime o resultado do Insertion Sort
    imprimirArray(vetor1, tamanho); // imprime o vetor ordenado
    printf("Comparações: %d\nTrocas: %d\n", comp, trocas); // imprime o número de comparações e trocas

    // Bubble Sort
    trocas = comp = 0; // resetando os contadores
    bubble_sort(vetor2, tamanho, &trocas, &comp); // chama a função de Bubble Sort
    printf("\nOrdenação com Bubble Sort:\n"); // imprime o resultado do Bubble Sort
    imprimirArray(vetor2, tamanho); // imprime o vetor ordenado
    printf("Comparações: %d\nTrocas: %d\n", comp, trocas); //   imprime o número de comparações e trocas

    // Quick Sort
    trocas = comp = 0; // resetando os contadores
    quickSort(vetor3, 0, tamanho - 1, &trocas, &comp); // chama a função de Quick Sort
    printf("\nOrdenação com Quick Sort:\n"); //   imprime o resultado do Quick Sort
    imprimirArray(vetor3, tamanho); // imprime o vetor ordenado
    printf("Comparações: %d\nTrocas: %d\n", comp, trocas); // imprime o número de comparações e trocas

    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}
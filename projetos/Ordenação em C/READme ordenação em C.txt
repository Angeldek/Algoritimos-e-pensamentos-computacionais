📊 Comparação de Algoritmos de Ordenação em C

Este projeto implementa e compara três algoritmos clássicos de ordenação: Insertion Sort, Bubble Sort e Quick Sort, utilizando a linguagem C. O objetivo é demonstrar o funcionamento de cada algoritmo e contabilizar o número de comparações e trocas realizadas durante a ordenação de um vetor fixo.

📘 Descrição do Problema

O objetivo é ordenar vetores de inteiros e comparar o desempenho de três algoritmos clássicos:

Insertion Sort: escolhido por sua simplicidade e eficiência em vetores pequenos ou parcialmente ordenados.
Bubble Sort: incluído por ser didático e fácil de entender, embora ineficiente em grandes volumes.
Quick Sort: selecionado por ser um dos algoritmos mais rápidos na prática, com bom desempenho médio. Esses métodos foram escolhidos por representarem diferentes paradigmas de ordenação: simples, iterativo e recursivo.
📌 Funcionalidades

Contagem de comparações e trocas realizadas por cada algoritmo.
Impressão do vetor antes e depois da ordenação.
Comparação clara entre os algoritmos com base em desempenho lógico.
🧪 Exemplo de Entrada

int vetorOriginal[] = {4, 6, 0, 6, 2, 3, 5, 1};

📤 Saída Esperada

Antes da ordenação: 4 6 0 6 2 3 5 1

Insertion Sort: 0 1 2 3 4 5 6 6 Comparações: 22 Trocas: 16

Bubble Sort: 0 1 2 3 4 5 6 6 Comparações: 28 Trocas: 16

Quick Sort: 0 1 2 3 4 5 6 6 Comparações: 17 Trocas: 13

🛠️ Como compilar e executar

Compile o código com gcc: gcc ordenacao.c -o ordenacao
Execute o programa: ./ordenacao
📚 Estrutura do Código

insertionSort() – Ordena e conta operações.
bubble_sort() – Ordena e conta operações.
quickSort() – Chama particiona() para dividir e ordenar.
imprimirArray() – Exibe o vetor.
main() – Inicializa vetores, executa os algoritmos e exibe resultados.
✅ Conclusão

Quick Sort é o melhor método entre os três, combinando baixo número de operações com alta escalabilidade. Insertion Sort pode ser útil em casos específicos, enquanto Bubble Sort deve ser evitado em aplicações reais.
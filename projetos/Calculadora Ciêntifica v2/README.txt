# Calculadora Científica em C | Projeto Modular (v2.0)

Este projeto apresenta a segunda versão de uma calculadora desenvolvida em Linguagem C. O objetivo desta refatoração (`v2.0`) foi construir um sistema altamente **modular** e **escalável** para operações científicas e estatísticas.

A arquitetura do código é baseada no uso de:
* **Funções de Serviço:** Cada cálculo (desde a adição até o Desvio Padrão) é isolado em uma função C dedicada.
* **Structs e Arrays:** Utilização de uma `struct` e um array fixo para gerenciar e armazenar o histórico de operações.
* **Alocação Dinâmica de Memória:** Uso de `malloc` para lidar eficientemente com conjuntos variáveis de dados (como matrizes ou N números em operações básicas).

---

## Funcionalidades Implementadas

O programa oferece um menu de 27 opções, cobrindo diversas áreas da matemática e estatística:

### 1. Operações Aritméticas e de Base

| ID | Operação | Descrição |
| :---: | :--- | :--- |
| **1-4** | Aritméticas Básicas | Adição, Subtração, Multiplicação e Divisão (suporte a N números). |
| **20** | Resto da Divisão | Módulo de números inteiros. |
| **22** | Diferença Positiva | Retorna o valor absoluto da diferença entre dois números. |

### 2. Funções Científicas

* **Potenciação** (5) e **Radiciação** (6)
* **Raíz Quadrada** (7) e **Raíz Cúbica** (21)
* **Trigonometria:** Seno (8), Cosseno (9), Tangente (10)
* **Logaritmos:** Natural (16), Base 10 (17), Base 2 (18)
* **Fatorial** (15)
* **Mantissa e Expoente** (19): Separa o número em sua forma de ponto flutuante normalizada.

### 3. Estatística e Análise

* **Média** (11)
* **Mediana** (12)
* **Desvio Padrão** (13)
* **Máxima e Mínima** (25)
* **Derivada** (14): Cálculo aproximado usando diferenças finitas.
* **MMC** (23) e **MDC** (24)

### 4. Álgebra Linear (Matrizes)

* **Matriz Soma** (26): Soma de todos os elementos de uma matriz.
* **Matriz Multiplicação** (27): Multiplicação entre Matriz A e B (com validação de dimensões).

### Recurso de Histórico

Todas as operações concluídas são registradas em uma lista (`historico`) e exibidas ao final de cada cálculo, detalhando operandos e resultado.

---

## Detalhes de Implementação

* **Linguagem:** C
* **Estruturas Chave:** `struct Operacao`, Arrays (estáticos e alocados dinamicamente).
* **Compilação:** Requer a vinculação da biblioteca matemática.

### Instruções de Compilação

Para compilar o código (salvo como, por exemplo, `cientifica.c`), use a flag **`-lm`**:

```bash
gcc cientifica.c -o calculadora -lm
./calculadora
---

## Colaboradores

Este projeto foi desenvolvido com a colaboração dos seguintes membros:

| Colaborador | Contribuição Principal |
| :--- | :--- |
| **Aline Herrero** | Desenvolvimento Completo do Sistema e Lógica Central |
| **Luis Angelo** | Desenvolvimento Completo do Sistema e Funções Matemáticas |
| **Jamilly Duda** | Estrutura de Código, Revisão e Documentação do `README.md` |
| **Syang** | Testes e Implementação de Estruturas de Dados |

---

## Exemplo de Uso (Terminal)

Este é um exemplo da interação do usuário com a calculadora para uma operação de Potenciação e a visualização do histórico subsequente:

```bash
----CALCULADORA CIENTÍFICA----
1 - Adição
...
5 - Potenciação
...
27 - Matriz Multiplicação
Escolha a opção desejada: 5
Digite a base:
5
Digite o expoente:
3
O resultado da potenciacao e: 125.00

Histórico de Operações:
ID: 1 | Tipo: Potenciacao | a1: 5.00 | a2: 3.00 | Resultado: 125.00

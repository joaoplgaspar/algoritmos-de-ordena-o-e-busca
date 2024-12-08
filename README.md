# Lista de Atividades: Reforço de Estudo para a Prova 02

### Nome: João Pedro Lima Gaspar
### RA: 197331

## Índice

1. [Binary Search](#1-binary-search)
2. [Interpolation Search](#2-interpolation-search)
3. [Jump Search](#3-jump-search)
4. [Exponential Search](#4-exponential-search)
5. [Shell Sort](#5-shell-sort)
6. [Merge Sort](#6-merge-sort)
7. [Selection Sort](#7-selection-sort)
8. [Bucket Sort](#8-bucket-sort)
9. [Radix Sort](#9-radix-sort)
10. [Quick Sort](#10-quick-sort)
11. [Ternary Search](#11-ternary-search)
12. [Comparação de Algoritmos de Busca](#12-comparação-de-algoritmos-de-busca)
13. [Comparação de Algoritmos de Ordenação](#13-comparação-de-algoritmos-de-ordenação)
14. [Análise de Complexidade](#14-análise-de-complexidade)
15. [Busca e Ordenação em Strings](#15-busca-e-ordenação-em-strings)
16. [Aplicação Prática de Busca](#16-aplicação-prática-de-busca)
17. [Busca e Ordenação em Dados Reais](#17-busca-e-ordenação-em-dados-reais)
18. [Ordenação Estável e Instável](#18-ordenação-estável-e-instável)
19. [Análise Visual dos Algoritmos](#19-análise-visual-dos-algoritmos)
20. [Desafios de Implementação](#20-desafios-de-implementação)

## 1. Binary Search

- **Descrição:** O algoritmo Binary Search é utilizado para encontrar o índice de um elemento em uma lista ordenada. Funciona ao dividir a lista repetidamente pela metade e comparando o elemento central com o alvo.
- **Importância da Ordem:** A lista deve estar ordenada para que o Binary Search funcione corretamente, pois a técnica depende de eliminar metade da lista com base na comparação do elemento do meio. Se a lista estiver desordenada, não será possível determinar de maneira confiável em qual metade o elemento pode estar.
- **Exemplo:** Se procurarmos pelo número 10 na lista ordenada [2, 3, 4, 10, 40], o algoritmo começará no meio (4), depois se moverá para a direita até encontrar 10.

![image](https://github.com/user-attachments/assets/c671276f-be6b-43ff-8401-09e9049247d4)
![image](https://github.com/user-attachments/assets/27b484f6-cebe-4092-96d9-e4e58296db5a)


## 2. Interpolation Search

- **Descrição:** O Interpolation Search é uma variante do Binary Search que estima a posição do valor alvo, assumindo uma distribuição linear dos valores.
- **Casos Favoráveis:** Funciona mais eficientemente em listas ordenadas com valores distribuídos uniformemente, onde pode realizar menos comparações do que o Binary Search.
- **Comparação:** Em listas com distribuição uniforme, o Interpolation Search pode ser mais rápido que o Binary Search.

![image](https://github.com/user-attachments/assets/1e6cfb82-4816-4a03-aa36-598ab8c79536)
![image](https://github.com/user-attachments/assets/c7597ecf-06ab-41e8-9200-29847deddad3)


## 3. Jump Search

- **Descrição:** O Jump Search é uma técnica de busca que atravessa uma lista saltando blocos de elementos em vez de um por um. Isso é feito até encontrar um bloco que contém o elemento alvo.
- **Tamanho do Salto:** O tamanho ideal do salto é geralmente a raiz quadrada do tamanho da lista (`√n`).
- **Comparação de Desempenho:** O Jump Search é geralmente mais rápido que a busca linear e pode ser comparado com o Binary Search em listas de diferentes tamanhos.

![image](https://github.com/user-attachments/assets/35b4d601-c5c2-4b91-99ee-d51c1fe60794)
![image](https://github.com/user-attachments/assets/30fc8b87-0ecd-4c9b-baa6-3b4435757270)



## 4. Exponential Search

- **Descrição:** Combina elementos do Jump Search e Binary Search para localizar rapidamente um elemento em uma lista ordenada. Primeiro, encontra um intervalo onde o elemento pode estar, depois usa o Binary Search nesse intervalo.
- **Análise de Desempenho:** Muito eficaz em listas grandes, pois rapidamente reduz a área de busca potencial.

![image](https://github.com/user-attachments/assets/27198958-be58-4887-8410-689928e68bac)
![image](https://github.com/user-attachments/assets/b70ee4a0-bbf5-4719-bd9f-200524bc9056)


## 5. Shell Sort

- **Descrição:** O Shell Sort é uma generalização do Insertion Sort que melhora a eficiência comparando elementos distantes em vez de adjacentes.
- **Sequências de Intervalo:** Diferentes sequências de intervalo (como Shell, Knuth, Hibbard) podem ser usadas, afetando a eficiência.
- **Comparação de Desempenho:** A escolha da sequência de intervalos pode impactar significativamente a eficiência do algoritmo.

![image](https://github.com/user-attachments/assets/82f97b3d-a332-4c60-8f2a-59d22d2c506a)
![image](https://github.com/user-attachments/assets/77ddab7f-f25e-4c9b-af27-e47428f04697)



## 6. Merge Sort

- **Descrição:** O Merge Sort é um algoritmo de ordenação que usa a técnica de "dividir para conquistar". Divide a lista em sublistas menores, ordena essas sublistas e as combina para formar a lista ordenada.
- **Ordenação de Strings:** Pode ser adaptado para ordenar strings alfabeticamente.

![image](https://github.com/user-attachments/assets/b60c86e7-30f2-4b47-bef3-9ac74ed075f5)
![image](https://github.com/user-attachments/assets/b6b84653-ce70-4848-84ca-e4d210a1af55)



## 7. Selection Sort

- **Descrição:** O Selection Sort ordena repetidamente encontrando o menor elemento restante e trocando-o para a posição correta.
- **Análise Detalhada:** Mostra cada iteração para entender como a lista é reorganizada passo a passo.
- **Desempenho:** Mais eficiente em listas pequenas devido à sua simplicidade.

![image](https://github.com/user-attachments/assets/ceda062f-00bf-4e72-bfdd-26b96cb330f6)
![image](https://github.com/user-attachments/assets/dc85b1c9-c571-4425-8ba7-8a34f011a61d)



## 8. Bucket Sort

- **Descrição:** O Bucket Sort distribui elementos em baldes, ordena cada balde individualmente e os combina.
- **Adaptação para Inteiros:** Pode ser adaptado para ordenar inteiros positivos em intervalos maiores.

![image](https://github.com/user-attachments/assets/e5e264c2-2358-4c30-adac-f330858a50b3)
![image](https://github.com/user-attachments/assets/e3759589-7e1a-4d3d-92c1-a8805d4bee31)



## 9. Radix Sort

- **Descrição:** Ordena inteiros processando dígitos individualmente. Funciona bem para números com dígitos de tamanho fixo.
- **Diferentes Bases:** Pode lidar com diferentes bases numéricas (como base 10 e base 2).

![image](https://github.com/user-attachments/assets/550151c5-df88-4688-b37a-6cf7f5d98ce0)
![image](https://github.com/user-attachments/assets/71bd60ef-e3f8-4259-acac-33e124e9b920)



## 10. Quick Sort

- **Descrição:** O Quick Sort é um algoritmo de ordenação eficiente que utiliza o conceito de pivôs para dividir e conquistar.
- **Critérios para Pivô:** Diferentes escolas para selecionar o pivô (primeiro, último, ou elemento do meio) podem impactar o desempenho.
- **Análise de Desempenho:** Avalia o desempenho em listas quase ordenadas versus completamente desordenadas.

![image](https://github.com/user-attachments/assets/e1a08f6b-5d2b-437c-8f00-fef09ac2df6f)
![image](https://github.com/user-attachments/assets/1e2ab306-fcb9-47e7-af34-1bbd3698b2a2)



## 11. Ternary Search

- **Descrição:** Busca um elemento em uma lista ordenada dividindo-a em três partes. Pode ser mais eficiente que o Binary Search em certos casos.

![image](https://github.com/user-attachments/assets/087f52d3-3251-4ef2-bdc2-78c99a6d3c13)
![image](https://github.com/user-attachments/assets/e540e10a-b5ec-4966-95f9-d4cc346497dd)



## 12. Comparação de Algoritmos de Busca

- **Descrição:** Compara os tempos de execução de diferentes algoritmos de busca (Binary, Interpolation, Jump, Exponential) em listas de tamanhos variados.

![image](https://github.com/user-attachments/assets/efdc8baa-fd3b-41d8-886b-bfe021675652)
![image](https://github.com/user-attachments/assets/35237508-2af9-45b0-b7f6-f6a7103bd076)


## 13. Comparação de Algoritmos de Ordenação

- **Descrição:** Ordena a mesma lista usando diferentes algoritmos (Shell, Merge, Selection, Quick, Bucket, Radix) e registra tempos de execução e comparações.

![image](https://github.com/user-attachments/assets/f48c6c7d-31d2-4f2f-b8d0-4c68147e7fa3)
![image](https://github.com/user-attachments/assets/904da39a-fc21-448c-8580-26be263d0abe)


## 14. Análise de Complexidade

- **Descrição:** Analisa a complexidade de tempo e espaço de cada algoritmo de busca e ordenação listado.

![image](https://github.com/user-attachments/assets/6cd7f0d5-f689-444b-b2f1-7b9c6e371336)
![image](https://github.com/user-attachments/assets/512a9751-4912-4a9e-be56-9fc78d46a109)


## 15. Busca e Ordenação em Strings

- **Descrição:** Adapta Merge Sort e Quick Sort para ordenar palavras alfabeticamente. Usa Binary Search para verificar a presença de uma palavra específica em uma lista ordenada.

![image](https://github.com/user-attachments/assets/a7bfaad7-decc-421b-b067-376770300d6d)
![image](https://github.com/user-attachments/assets/9afb3743-f0e9-4af1-8390-e3d21de8d605)


## 16. Aplicação Prática de Busca

- **Descrição:** Usa Binary Search para procurar por ISBN em uma lista ordenada de registros de biblioteca.

![image](https://github.com/user-attachments/assets/4b3d13ab-31a5-4de7-b4c1-8fd5a82efab7)
![image](https://github.com/user-attachments/assets/6d8a1d26-085f-411f-a16a-9e1f93d0af49)


## 17. Busca e Ordenação em Dados Reais

- **Descrição:** Implementa Bucket Sort para ordenar notas de alunos, seguidas de Interpolation Search para encontrar notas específicas.

![image](https://github.com/user-attachments/assets/e48754ce-1316-4515-94c8-57d1bfebe266)


## 18. Ordenação Estável e Instável

- **Descrição:** Identifica quais algoritmos de ordenação são estáveis, explicando o conceito e demonstrando com exemplos.

![image](https://github.com/user-attachments/assets/b53d1fd8-da33-44de-a945-cd6cd9f135b5)
![image](https://github.com/user-attachments/assets/44229044-cb5a-4577-a297-497c95711d62)



## 19. Análise Visual dos Algoritmos

- **Descrição:** Cria gráficos para ilustrar como Merge Sort, Quick Sort e Selection Sort reorganizam elementos em cada etapa.

![image](https://github.com/user-attachments/assets/e26f8f69-3504-4ce9-9be3-88479917c3fe)
![image](https://github.com/user-attachments/assets/6a8a66d5-7de7-48e7-9a13-02b493d8dfd5)



## 20. Desafios de Implementação

- **Descrição:** Cria um programa interativo que permite ao usuário escolher um algoritmo para ordenar uma lista ou procurar um elemento, oferecendo comparações automáticas entre métodos.

![image](https://github.com/user-attachments/assets/d33213f6-395a-450e-8af7-501fc5248437)

![image](https://github.com/user-attachments/assets/31215b3d-ab74-48b7-8dc7-fb1672a17f74)


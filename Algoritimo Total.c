#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Protótipos das funções
int binarySearch(int arr[], int left, int right, int target);
int interpolationSearch(int arr[], int size, int target);
int jumpSearch(int arr[], int size, int target);
int exponentialSearch(int arr[], int size, int target);
int ternarySearch(int arr[], int left, int right, int target);
void shellSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void selectionSort(int arr[], int size);
void bucketSort(float arr[], int size);
void radixSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

void demonstrateBinarySearch();
void demonstrateInterpolationSearch();
void demonstrateJumpSearch();
void demonstrateExponentialSearch();
void demonstrateShellSort();
void demonstrateMergeSort();
void demonstrateSelectionSort();
void demonstrateBucketSort();
void demonstrateRadixSort();
void demonstrateQuickSort();
void demonstrateTernarySearch();
void compareSearchAlgorithms();
void compareSortingAlgorithms();
void analyzeComplexity();
void orderingAndSearchingStrings();
void practicalISBNBinarySearch();
void dataRealSortingAndSearching();
void stableAndUnstableSorting();
void visualizeSortingAlgorithms();
void interactiveMenu();

// Função auxiliar para troca
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Implementações das funções de busca
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[prev] < target) {
        if (step >= size || arr[step] >= target) break;
        prev = step;
        step += sqrt(size);
    }
    for (int i = prev; i < fmin(step, size); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < size && arr[i] <= target) i *= 2;
    return binarySearch(arr, i / 2, fmin(i, size - 1), target);
}

int ternarySearch(int arr[], int l, int r, int target) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;
        if (target < arr[mid1]) return ternarySearch(arr, l, mid1 - 1, target);
        if (target > arr[mid2]) return ternarySearch(arr, mid2 + 1, r, target);
        return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
    return -1;
}

// Implementações das funções de ordenação
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void bucketSort(float arr[], int size) {
    int i, j, k;
    int bucketCount = 10; // Número de baldes
    float buckets[bucketCount][size];
    int bucketSizes[bucketCount];
    for (i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
    }
    for (i = 0; i < size; i++) {
        int index = arr[i] * bucketCount;
        buckets[index][bucketSizes[index]++] = arr[i];
    }
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            selectionSort((int*)buckets[i], bucketSizes[i]);
        }
    }
    k = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funções de demonstração das implementações dos algoritmos
void demonstrateBinarySearch() {
    printf("1 - Demonstrar Binary Search\n");
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    printf("Binary Search: Elemento %d encontrado no índice %d\n\n", target, result);
}

void demonstrateInterpolationSearch() {
    printf("2 - Demonstrar Interpolation Search\n");
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;
    int index = interpolationSearch(arr, n, target);
    printf("Interpolation Search: Elemento %d encontrado no índice %d\n\n", target, index);
}

void demonstrateJumpSearch() {
    printf("3 - Demonstrar Jump Search\n");
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, n, target);
    printf("Jump Search: Elemento %d encontrado no índice %d\n\n", target, index);
}

void demonstrateExponentialSearch() {
    printf("4 - Demonstrar Exponential Search\n");
    int arr[] = {3, 5, 7, 9, 10, 15, 20, 25};
    int target = 15;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = exponentialSearch(arr, n, target);
    printf("Exponential Search: Elemento %d encontrado no índice %d\n\n", target, result);
}

void demonstrateShellSort() {
    printf("5 - Demonstrar Shell Sort\n");
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    printf("Shell Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateMergeSort() {
    printf("6 - Demonstrar Merge Sort\n");
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printf("Merge Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateSelectionSort() {
    printf("7 - Demonstrar Selection Sort\n");
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Selection Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateBucketSort() {
    printf("8 - Demonstrar Bucket Sort\n");
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Bucket Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateRadixSort() {
    printf("9 - Demonstrar Radix Sort\n");
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printf("Radix Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateQuickSort() {
    printf("10 - Demonstrar Quick Sort\n");
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Quick Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demonstrateTernarySearch() {
    printf("11 - Demonstrar Ternary Search\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int index = ternarySearch(arr, 0, n - 1, target);
    printf("Ternary Search: Elemento %d encontrado no índice %d\n\n", target, index);
}

// 12. Comparação de Algoritmos de Busca
void compareSearchAlgorithms() {
    printf("12 - Comparação de Algoritmos de Busca\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calcular tempo do Binary Search
    clock_t start = clock();
    binarySearch(arr, 0, n - 1, target);
    clock_t end = clock();
    printf("Binary Search levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calcular tempo do Interpolation Search
    start = clock();
    interpolationSearch(arr, n, target);
    end = clock();
    printf("Interpolation Search levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calcular tempo do Jump Search
    start = clock();
    jumpSearch(arr, n, target);
    end = clock();
    printf("Jump Search levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calcular tempo do Exponential Search
    start = clock();
    exponentialSearch(arr, n, target);
    end = clock();
    printf("Exponential Search levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\n");
}

// 13. Comparação de Algoritmos de Ordenação
void compareSortingAlgorithms() {
    printf("13 - Comparação de Algoritmos de Ordenação\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calcular tempo do Quick Sort
    int arrCopy[n];
    memcpy(arrCopy, arr, n * sizeof(int));
    clock_t start = clock();
    quickSort(arrCopy, 0, n - 1);
    clock_t end = clock();
    printf("Quick Sort levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calcular tempo do Merge Sort
    memcpy(arrCopy, arr, n * sizeof(int));
    start = clock();
    mergeSort(arrCopy, 0, n - 1);
    end = clock();
    printf("Merge Sort levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Calcular tempo do Selection Sort
    memcpy(arrCopy, arr, n * sizeof(int));
    start = clock();
    selectionSort(arrCopy, n);
    end = clock();
    printf("Selection Sort levou %lf segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\n");
}

// 14. Análise de Complexidade
void analyzeComplexity() {
    printf("14 - Análise de Complexidade\n");
    printf("Binary Search: O(log n) tempo, O(1) espaço\n");
    printf("Interpolation Search: O(log log n) tempo melhor caso, O(n) pior caso\n");
    printf("Jump Search: O(√n) tempo, O(1) espaço\n");
    printf("Exponential Search: O(log n) tempo, O(1) espaço\n");
    printf("Shell Sort: O(n log² n) tempo pior caso\n");
    printf("Merge Sort: O(n log n) tempo, O(n) espaço\n");
    printf("Selection Sort: O(n²) tempo, O(1) espaço\n");
    printf("Bucket Sort: O(n + k) tempo, O(n + k) espaço\n");
    printf("Radix Sort: O(nk) tempo, O(n + k) espaço\n");
    printf("Quick Sort: O(n log n) tempo médio, O(n²) pior caso, O(log n) espaço\n");
    printf("Ternary Search: O(log₃ n) tempo, O(1) espaço\n");
    printf("\n");
}

// 15. Busca e Ordenação em Strings
void mergeSortStrings(char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortStrings(arr, left, mid);
        mergeSortStrings(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;
        char *L[n1], *R[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (strcmp(L[i], R[j]) <= 0) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
}

int binarySearchStrings(char *arr[], int left, int right, char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(arr[mid], target);
        if (res == 0) return mid;
        if (res < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void orderingAndSearchingStrings() {
    printf("15 - Busca e Ordenação em Strings\n");
    char *arr[] = {"banana", "apple", "orange", "mango"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for(int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    mergeSortStrings(arr, 0, n - 1);

    printf("Array ordenado: ");
    for(int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    char *target = "orange";
    int index = binarySearchStrings(arr, 0, n - 1, target);
    printf("Binary Search para strings: Elemento '%s' encontrado no índice %d\n\n", target, index);
}

// 16. Aplicação Prática de Busca
void practicalISBNBinarySearch() {
    printf("16 - Aplicação Prática de Busca\n");
    int isbns[] = {9780306406157, 9780679783272, 9780451524935};
    int target = 9780679783272;
    int n = sizeof(isbns) / sizeof(isbns[0]);
    int result = binarySearch(isbns, 0, n - 1, target);
    printf("ISBN %d encontrado no índice %d\n\n", target, result);
}

// 17. Busca e Ordenação em Dados Reais
void dataRealSortingAndSearching() {
    printf("17 - Busca e Ordenação em Dados Reais\n");
    float notas[] = {98.5, 67.7, 89.2, 45.5, 100.0};
    int n = sizeof(notas) / sizeof(notas[0]);

    printf("Notas originais: ");
    for(int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }
    printf("\n");

    bucketSort(notas, n);

    printf("Notas ordenadas: ");
    for(int i = 0; i < n; i++) {
        printf("%.1f ", notas[i]);
    }
    printf("\n");

    float target = 89.2;
    int index = interpolationSearch((int*)notas, n, (int)target);
    printf("Interpolation Search para notas: Nota %.1f encontrada no índice %d\n\n", target, index);
}

// 18. Ordenação Estável e Instável
void stableAndUnstableSorting() {
    printf("18 - Ordenação Estável e Instável\n");
    printf("Merge Sort: Estável\n");
    printf("Quick Sort: Instável\n");
    printf("Selection Sort: Instável\n");
    printf("Insertion Sort: Estável\n");
    printf("Bubble Sort: Estável\n");
    printf("Shell Sort: Instável\n");
    printf("Bucket Sort: Estável, dependendo da ordenação dentro dos buckets\n");
    printf("Radix Sort: Estável\n");
    printf("Observação: A estabilidade de um algoritmo de ordenação refere-se à manutenção da ordem relativa de elementos iguais.\n\n");
}

// 19. Análise Visual dos Algoritmos
void visualizeSortingAlgorithms() {
    printf("19 - Análise Visual dos Algoritmos\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Passos do Selection Sort:\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);

        printf("Após passo %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("\n");
}

// 20. Desafios de Implementação
void interactiveMenu() {
    int choice;
    while (1) {
        printf("20 - Desafios de Implementação\n");
        printf("Escolha um algoritmo para demonstrar:\n");
        printf("1. Binary Search\n");
        printf("2. Interpolation Search\n");
        printf("3. Jump Search\n");
        printf("4. Exponential Search\n");
        printf("5. Shell Sort\n");
        printf("6. Merge Sort\n");
        printf("7. Selection Sort\n");
        printf("8. Bucket Sort\n");
        printf("9. Radix Sort\n");
        printf("10. Quick Sort\n");
        printf("11. Ternary Search\n");
        printf("12. Comparação de Algoritmos de Busca\n");
        printf("13. Comparação de Algoritmos de Ordenação\n");
        printf("14. Análise de Complexidade\n");
        printf("15. Busca e Ordenação em Strings\n");
        printf("16. Aplicação Prática de Busca\n");
        printf("17. Busca e Ordenação em Dados Reais\n");
        printf("18. Ordenação Estável e Instável\n");
        printf("19. Análise Visual dos Algoritmos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                demonstrateBinarySearch();
                break;
            case 2:
                demonstrateInterpolationSearch();
                break;
            case 3:
                demonstrateJumpSearch();
                break;
            case 4:
                demonstrateExponentialSearch();
                break;
            case 5:
                demonstrateShellSort();
                break;
            case 6:
                demonstrateMergeSort();
                break;
            case 7:
                demonstrateSelectionSort();
                break;
            case 8:
                demonstrateBucketSort();
                break;
            case 9:
                demonstrateRadixSort();
                break;
            case 10:
                demonstrateQuickSort();
                break;
            case 11:
                demonstrateTernarySearch();
                break;
            case 12:
                compareSearchAlgorithms();
                break;
            case 13:
                compareSortingAlgorithms();
                break;
            case 14:
                analyzeComplexity();
                break;
            case 15:
                orderingAndSearchingStrings();
                break;
            case 16:
                practicalISBNBinarySearch();
                break;
            case 17:
                dataRealSortingAndSearching();
                break;
            case 18:
                stableAndUnstableSorting();
                break;
            case 19:
                visualizeSortingAlgorithms();
                break;
            case 0:
                exit(0);
            default:
                printf("Escolha inválida\n");
        }
    }
}

int main() {
    interactiveMenu();
    return 0;
}
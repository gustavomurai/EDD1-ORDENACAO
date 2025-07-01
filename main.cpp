/*
 * Atividade de Estrutura de Dados - Algoritmos de Ordenação
 * Código realizado por: Gustavo e Igor Murai
 * Algoritmos implementados: COUNTING SORT e MERGE SORT
 * Vetor de exemplo utilizado: {4, 2, 2, 8, 3, 3, 1}
 */

#include <iostream>
using namespace std;

// ========================
// FUNÇÃO: Imprimir Vetor
// ========================
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ========================
// COUNTING SORT
// ========================
void countingSort(int arr[], int n) {
    // Encontrar o maior valor no vetor
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // Criar vetor de contagem e inicializar com zero
    int* count = new int[max + 1]{0};

    // Contar a frequência de cada número
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Reconstruir o vetor original em ordem crescente
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Liberar memória do vetor de contagem
    delete[] count;
}

// ========================
// MERGE SORT
// ========================

// Função auxiliar que junta dois subvetores em ordem
void merge(int arr[], int left, int mid, int right) {
    // Tamanhos dos dois subvetores
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Vetores temporários
    int L[n1], R[n2];

    // Copiar dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Juntar os dois vetores ordenados
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copiar elementos restantes de L, se houver
    while (i < n1)
        arr[k++] = L[i++];

    // Copiar elementos restantes de R, se houver
    while (j < n2)
        arr[k++] = R[j++];
}

// Função principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a metade esquerda
        mergeSort(arr, left, mid);
        // Ordena a metade direita
        mergeSort(arr, mid + 1, right);
        // Junta as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// ========================
// FUNÇÃO PRINCIPAL (main)
// ========================
int main() {
    // Vetor base usado na aula para todos os testes
    int vetor1[] = {4, 2, 2, 8, 3, 3, 1};
    int vetor2[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(vetor1) / sizeof(vetor1[0]);

    // Imprimir vetor original
    cout << "Vetor original: ";
    printArray(vetor1, n);

    // Aplicar COUNTING SORT
    countingSort(vetor1, n);
    cout << "Vetor ordenado (Counting Sort): ";
    printArray(vetor1, n);

    // Aplicar MERGE SORT
    mergeSort(vetor2, 0, n - 1);
    cout << "Vetor ordenado (Merge Sort): ";
    printArray(vetor2, n);

    return 0;
}

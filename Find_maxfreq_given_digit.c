#include <stdio.h>
#include <stdlib.h>

void findElements(int arr[], int N, int K) {
    int max_freq = 0;
    int *result = (int*) malloc(N * sizeof(int));
    int result_count = 0;

    for (int i = 0; i < N; i++) {
        int num = arr[i];
        int freq = 0;

        while (num > 0) {
            if (num % 10 == K) {
                freq++;
            }
            num /= 10;
        }

        if (freq > max_freq) {
            max_freq = freq;
            result_count = 0;
            result[result_count++] = arr[i];
        } else if (freq == max_freq && freq > 0) {
            result[result_count++] = arr[i];
        }
    }

    if (result_count > 0) {
        printf("Numbers with the maximum frequency of digit %d are:\n", K);
        for (int i = 0; i < result_count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("No number contains the digit %d\n", K);
    }
}

int main() {
    int *array;
    int N, i, K;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    array = (int*) malloc(N * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the digit: ");
    scanf("%d", &K);

    findElements(array, N, K);

    return 0;
}

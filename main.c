#include <stdio.h>

#define SIZE_ARR(arr) sizeof(arr)/sizeof(arr[0])

enum arrays {a, b, c, all};

static void show_arr(const int arr[], const int len)
{
    int i = 0;

    for(; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}  

#if 0
static int min_value(int *arr[], int len[])
{
    static int index_a = 0;
    static int index_b = 0;
    static int index_c = 0;

    if (index_a < len[a] && (index_b >= len[b] || arr[a][index_a] < arr[b][index_b])) {
        if (index_c >= len[c] || arr[a][index_a] < arr[c][index_c]) {
            return arr[a][index_a++];
        }
        else {
            return arr[c][index_c++];
        }
    } else {
        if (index_b < len[b] && (index_c >= len[c] || arr[b][index_b] < arr[c][index_c])) {
            return arr[b][index_b++];
        }
        else {
            return arr[c][index_c++];
        }
    }
}

#else

static int min_value(int *arr[], int len[])
{
    if (len[a] > 0 && (len[b] <= 0 || *arr[a] < *arr[b])) {
        if (len[c] <= 0 || *arr[a] < *arr[c]) {
            len[a]--;
            return *(arr[a]++);
        }
        else {
            len[c]--;
            return *(arr[c]++);
        }
    } else {
        if (len[b] > 0 && (len[c] <= 0 || *arr[b] < *arr[c])) {
            len[b]--;
            return *(arr[b]++);
        }
        else {
            len[c]--;
            return *(arr[c]++);
        }
    }
}
#endif

static void merge(int out[], int *arr[], int len[])
{
    int index;

    for (index = 0; index < len[all]; index++) {
        out[index] = min_value(arr, len);
    }
}

int main(void)
{
    int arr1[] = {2, 4, 6, 8, 28, 48, 100, 11151};
    int arr2[] = {0, 1, 3, 5, 7, 15};
    int arr3[] = {-6, -1, 10, 28};
    int *arr[] = {arr1, arr2, arr3, NULL};
    int output[SIZE_ARR(arr1) + SIZE_ARR(arr2) + SIZE_ARR(arr3)];
    int len[] = {SIZE_ARR(arr1), SIZE_ARR(arr2), SIZE_ARR(arr3), SIZE_ARR(output)};

    for (int i = 0; arr[i]; i++)
        show_arr(arr[i], len[i]);
    merge(output, arr, len);
    printf("After merge arrays:\n");
    show_arr(output, len[all]);

    return 0;
}
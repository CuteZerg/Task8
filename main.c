#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void bubble_sort(int *a, int n, int *k, int *e)
{
    int tmp;

    for (int i = 0; i < n-1;i++)
    {
        for (int j = 0; j < n - 1 - i;j++)
        {
            if (a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                *e = *e + 1;
            }
            *k = *k + 1;
        }
    }
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int *a, int low, int high,int *k,int *e)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&a[i], &a[j]);
                *e = *e + 1;
            }
        }
        *k = *k + 1;
    }
    if (i+1 != high)
    {
        swap(&a[i + 1], &a[high]);
        *e = *e + 1;
    }
    return (i + 1);
}


void quicksort(int *a, int low, int high, int *k, int *e)
{
    if (low < high)
    {
        int pi = partition(a, low, high, k, e);

        quicksort(a, low, pi - 1, k, e);
        quicksort(a, pi + 1, high, k, e);
    }
}


void insertion_sort(int *a, int n, int *k, int *e)
{
    int tmp, j;
    for(int i = 1;i < n;i++)
    {
        tmp = a[i];
        j = i;
        while( (j > 0) && (a[j-1] > tmp) )
        {
            a[j] = a[j-1];
            j = j-1;
            *e = *e + 1;
            *k = *k + 1;
        }
        a[j] = tmp;
        *k = *k + 1;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    printf("Введите длину массива:\n");
    scanf("%d", &n);
    printf("\nПострочно введите каждый элемент массива: \n");
    int *a = (int*) malloc(n*sizeof(int));
    int *b = (int*) malloc(n*sizeof(int));
    int *c = (int*) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }
    printf("\n");
    int k = 0;
    int e = 0;

    bubble_sort(a, n, &k, &e);

    printf("Bubble sort\n");
    for (int i = 0;i < n;i++)
        printf("%d\n", a[i]);
    printf("\nКол-во сравнений: %d\nКол-во перестановок: %d\n\n", k,e);

    k = 0;
    e = 0;

    quicksort(b, 0, n-1, &k, &e);

    printf("Quick sort\n");
    for (int i = 0;i < n;i++)
        printf("%d\n", b[i]);
    printf("\nКол-во сравнений: %d\nКол-во перестановок: %d\n\n", k,e);

    k = 0;
    e = 0;

    insertion_sort(c, n, &k, &e);

    printf("Insertion sort\n");
    for (int i = 0;i < n;i++)
        printf("%d\n", c[i]);
    printf("\nКол-во сравнений: %d\nКол-во перестановок: %d\n\n", k,e);



    return 0;
}


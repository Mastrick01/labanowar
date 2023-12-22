#include "clothes_db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(clothes** arr, int* n) {
    printf("Введите количество элементов для добавления: ");
    int num_items;
    scanf("%d", &num_items);

    *arr = (clothes*)realloc(*arr, (*n + num_items) * sizeof(clothes));
    if (*arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    for (int i = *n; i < *n + num_items; i++) {
        printf("Введите название товара %d: ", i + 1);
        scanf("%s", (*arr)[i].name);
        printf("Введите материал товара %d: ", i + 1);
        scanf("%s", (*arr)[i].material);
        printf("Введите цену товара %d: ", i + 1);
        scanf("%d", &(*arr)[i].price);
    }

    *n += num_items;
}

void read(clothes** arr, int* n) {
    FILE* file = fopen("clothes_db.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    int num_items;
    fread(&num_items, sizeof(int), 1, file);

    *arr = (clothes*)realloc(*arr, num_items * sizeof(clothes));
    if (*arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    fread(*arr, sizeof(clothes), num_items, file);
    *n = num_items;

    fclose(file);
}

void write(clothes* arr, int n) {
    if (n == 0) {
        printf("База данных пуста\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Элемент %d: Название: %s, Материал: %s, Цена: %d\n", i+1, arr[i].name, arr[i].material, arr[i].price);
    }
}

void search(clothes* arr, int n) {
    if (n == 0) {
        printf("База данных пуста\n");
        return;
    }

    printf("Введите критерий поиска:\n");
    printf("1. Название\n");
    printf("2. Цена\n");
    printf("3. Материал\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Введите название для поиска: ");
            char search_name[40];
            scanf("%s", search_name);

            for (int i = 0; i < n; i++) {
                if (strcmp(arr[i].name, search_name) == 0) {
                    printf("Товар найден:\n");

printf("Название: %s, Материал: %s, Цена: %d\n", arr[i].name, arr[i].material, arr[i].price);
                    return;
                }
            }
            printf("Товар не найден\n");
            break;

        case 2:
            printf("Введите максимальную цену для поиска: ");
            int max_price;
            scanf("%d", &max_price);

            for (int i = 0; i < n; i++) {
                if (arr[i].price <= max_price) {
                    printf("Название: %s, Материал: %s, Цена: %d\n", arr[i].name, arr[i].material, arr[i].price);
                }
            }
            break;

        case 3:
            printf("Введите материал для поиска: ");
            char search_material[40];
            scanf("%s", search_material);

            for (int i = 0; i < n; i++) {
                if (strcmp(arr[i].material, search_material) == 0) {
                    printf("Название: %s, Материал: %s, Цена: %d\n", arr[i].name, arr[i].material, arr[i].price);
                }
            }
            break;

        default:
            printf("Некорректный выбор\n");
    }
}

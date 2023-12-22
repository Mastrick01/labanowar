#include <stdio.h>
#include <stdlib.h>
#include "clothes_db.h"

int main() {
    clothes* database = NULL;
    int num_entries = 0;

    int choice;
    do {
        printf("1. Создать базу данных\n");
        printf("2. Загрузить базу данных\n");
        printf("3. Вывести базу данных\n");
        printf("4. Поиск\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(&database, &num_entries);
                break;
            case 2:
                read(&database, &num_entries);
                break;
            case 3:
                if (num_entries > 0) {
                    for (int i = 0; i < num_entries; i++) {
                        printf("Предмет %d: Название: %s, материал: %s, Цена: %d\n", i+1, database[i].name, database[i].material, database[i].price);
                    }
                } else {
                    printf("База данных пуста\n");
                }
                break;
            case 4:
                search(database, num_entries);
                break;
            case 5:
                printf("Выход из программы...\n");
                break;
            default:
                printf("Некорректный выбор\n");
        }

    } while (choice != 5);

    if (database) {
        free(database);  
    }

    return 0;
}
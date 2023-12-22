#ifndef CLOTHES_DB_H
#define CLOTHES_DB_H

typedef struct clothes {
    char name[40];
    char material[40];
    int price;
} clothes;

void create(clothes** arr, int* n);
void read(clothes** arr, int* n);
void write(clothes* arr, int n);
void search(clothes* arr, int n);

#endif 

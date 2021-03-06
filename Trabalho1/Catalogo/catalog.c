#include "../Catalogo/catalog.h"
#include "../Game/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

operation select_command(char *command) {
    if (!strcmp(command, "r"))
        return remove_duplicados;
    else if (!strcmp(command, "p"))
        return produtora;
    else if (!strcmp(command, "a"))
        return ano;
    else if (!strcmp(command, "i"))
        return imprime;
    else if (!strcmp(command, "u"))
        return posicao;
    else if (!strcmp(command, "mr"))
        return mover_direita;
    else if (!strcmp(command, "ml"))
        return mover_esquerda;

    return encerrar;
}

char **create_found_games_catalog(int size_search) {
    char **found_games = (char **)malloc(sizeof(char *) * size_search);

    if (found_games == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < size_search; i++) {
        found_games[i] = (char *)malloc(sizeof(char) * 256);
        if (found_games[i] == NULL)
            exit(EXIT_FAILURE);
    }
    return found_games;
}

void print_found_games(char **found_games, int number_of_searches) {
    for (int i = 0; i < number_of_searches; i++) {
        printf("%s\n", found_games[i]);
    }
}

void free_found_games_catalog(char **found_games, int size) {
    for (int i = 0; i < size; i++)
        free(found_games[i]);
    free(found_games);
}

void free_duplicate_games(int **duplicate_games) {
    free(*duplicate_games);
}

int *create_duplicate_games(int registers) {
    int *duplicate_games;

    duplicate_games = (int *)malloc(sizeof(int) * registers);

    if (duplicate_games == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < registers; i++)
        duplicate_games[i] = INEXISTENT_KEY;

    return duplicate_games;
}

void ajust_duplicate_key_games(int *duplicate_games, int N, int key) {
    for (int i = 0; i < N; i++) {
        if (duplicate_games[i] > key) {
            duplicate_games[i] -= 1;
        }
    }
}
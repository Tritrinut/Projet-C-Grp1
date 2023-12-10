#include "fonctions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



t_p_list CreateEmptyList(int level){
    t_p_list list;
    list.max_level = level;
    list.heads = (t_p_cell**)malloc(level*sizeof(t_p_cell*));
    for (int i = 0; i < level; i++){
        list.heads[i] = NULL;
    }
    return list;
}

p_p_cell CreateCell(int val, int level){
    p_p_cell cell = (p_p_cell) malloc(sizeof(t_p_cell));
    cell->value = val;
    cell->level = level;
    cell->next = (p_p_cell*) malloc(level*sizeof(p_p_cell));
    for (int i = 0; i < level; i++){
        cell->next[i] = NULL;
    }
    return cell;
}

void newHeadList(p_p_list s, int val, int level) {
    for (int i = 0; i < level; i++) {
        p_p_cell new;
        new = CreateCell(val, i);
        new->next[i] = s->heads[i];
        s->heads[i] = new;
    }
}
//on créer une cell, on la fait pointer vers le head puis on change ensuite
// la valeure du head pour la faire correspondre à celle de la cell


void printList(t_p_list list, int level) {
    t_p_cell *temp = list.heads[level];
    t_p_cell * temp_b = list.heads[0];
    printf("[list->head_%d @-]--", level);
    while (temp != NULL){
        if (level > 0) {
            if (temp->value != temp_b->value)  {
                printf("-----------");
                temp_b = temp_b->next[0];
            }
            else{
                printf(">[%3d @-]--", temp->value);
                temp = temp->next[level];
                temp_b = temp_b->next[0];
            }
        }
        else {
            printf(">[%3d @-]--", temp->value);
            temp = temp->next[level];
        }
    }
    if(level != 0) {
        while (temp_b != NULL) {
            printf("-----------");
            temp_b = temp_b->next[0];
        }
    }
    printf(">NULL\n");
}

void printfList(t_p_list list){
    for(int i = 0; i < list.max_level; i++){
        printList(list, i);
    }
}

void insertSortList (p_p_list list, int val, int level) {
    p_p_cell temp = NULL;
    p_p_cell prev = NULL;
    if(list->heads[0] == NULL){
        newHeadList(list, val, level);
        return;
    }
    for(int i = 0; i < level; i++){
        temp = list->heads[i];
        prev = temp;
        while(temp != NULL && temp->value < val){
            prev = temp;
            temp = temp->next[i];
        }
        p_p_cell new = CreateCell(val, level);
        if(temp == list->heads[i]){
            new->next[i] = &temp[i];
            prev->next[i] = new;
        }
        else{
            if(temp==NULL){
                prev->next[i] = new;
                new->next[i] = NULL;
            }
            else{
                new->next[i] = temp;
                prev->next[i] = new;
            }
        }
    }
}

void zeroList(p_p_list s, int level){
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < pow(2,level) - 1; j++) {
            p_p_cell new;
            new = CreateCell(0, i);
            new->next[i] = s->heads[i];
            s->heads[i] = new;
        }
    }
}


t_p_list lvl_list(p_p_list s, int n){
    int level = n-1;
    int nb_cell_0 = pow(2,n) - 1;
    t_p_list list = CreateEmptyList(n-1);
    for(int i = 0 ; i < level + 1; i++){
        int cpt = 1;
        int res = pow(2, i);
        for(int j = 0; j < nb_cell_0; j++) {
            if (cpt % res == 0) {
                p_p_cell new;
                new = CreateCell(nb_cell_0 + 1 - cpt, i);
                new->next[i] = s->heads[i];
                s->heads[i] = new;
            }
            cpt++;
        }
    }
    return list;
}

void recherche_0(p_p_list s, int val) {
    if(s->heads[0] == NULL){
        printf("\nListe vide, %d introuvable", val);
        return;
    }
    p_p_cell temp = s->heads[0];
    while(temp != NULL){
        if(temp->value == val){
            printf("\n%d se trouve dans la liste 0",val);
            return;
        }
        else{
            temp = *temp->next;
        }
    }
    printf("\n%d n'est pas dans la liste 0", val);
}



void recherche_globale(p_p_list s, int nb_lvl, int val) {
    if(s->heads[0] == NULL){
        printf("la liste est vide !");
        return;
    }
    for(int i = nb_lvl-1; i >= 0; i--){
        p_p_cell temp;
        if(s->heads[i] != NULL){
            temp = s->heads[i];
            while(temp != NULL){
                if(temp->value == val){
                    printf("\n%d se trouve a partir de la liste %d", val, i);
                    return;
                }
                else{
                    temp = *temp->next;
                }
            }
        }
    }
    printf("\n%d introuvable", val);
}

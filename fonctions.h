#ifndef PROJETS1L2_FONCTIONS_H
#define PROJETS1L2_FONCTIONS_H

typedef struct s_p_cell{
    int level;
    int value;
    struct s_p_cell **next;
}t_p_cell;

typedef struct s_p_list{
    int max_level;
    t_p_cell **heads;
}t_p_list;

typedef t_p_cell* p_p_cell;
typedef t_p_list* p_p_list;

t_p_list CreateEmptyList(int);

p_p_cell CreateCell(int, int);

void newHeadList(p_p_list , int, int);

void printList(t_p_list, int);

void printfList(t_p_list);

void insertSortList(p_p_list, int, int);

void zeroList(p_p_list s, int level);

t_p_list lvl_list(p_p_list, int);

void recherche_0(p_p_list, int);

void recherche_globale(p_p_list, int, int);

#endif //PROJETS1L2_FONCTIONS_H
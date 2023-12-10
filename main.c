#include "fonctions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_p_list l, s;
    clock_t debut, fin;
    double temps;
    int nb_lvl_h_l, find_nb, new_val;

    printf("Combien doit avoir de niveau votre agenda ? "); //ne pas mettre de trop grande valeur car le terminal
    scanf("%d", &nb_lvl_h_l);                               //est restreint (valeur conseillée --> 2)

    l = CreateEmptyList(nb_lvl_h_l);//nombre de niveaux


    printf("LVL_LIST :\n\n");
    lvl_list(&l, nb_lvl_h_l);
    printfList(l);
    printf("\n");

    s = CreateEmptyList(nb_lvl_h_l);

    printf("ZERO_LIST :\n\n");
    zeroList(&s, nb_lvl_h_l);
    printfList(s);
    printf("\n");


    debut = clock();
    for(int i; i < 1; i++){
        recherche_0(&l, find_nb);
    }
    fin = clock();
    temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("\n%f\n", temps);


    return 0;
}

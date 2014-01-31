#include<stdio.h>	
#include<stdlib.h>
#include <string.h>
#include"fonctions.h"
#include "fichier.h"

int main()
{

	system("TITLE Pendu");

	// ================== VARIABLES ========================= //

	int i = 0, mot_correct, nb_mot = 0, choix;
	char *pt_nb_mot = &nb_mot;
	char mot_saisie[100];
	char reponse;
	char *mot = mot_saisie;


	// ================== INSTRUCTIONS ========================= //

	nbMot(pt_nb_mot);

	printf("Pendu\n");

	do
	{
		printf("\n\n+---------------------------------+");
		printf("\n| Mode 1 joueur		| taper 1 |");
		printf("\n+---------------------------------+");
		printf("\n| Mode 2 joueur		| taper 2 |");
		printf("\n+---------------------------------+");
		printf("\n| Editer Dictionnaire	| taper 3 |");
		printf("\n+---------------------------------+");
		printf("\n| Quitter		| taper 0 |");
		printf("\n+---------------------------------+\n");
		printf("\nVotre choix : ");
		scanf("%d", &choix);
		fflush(stdin);

		switch (choix)
		{
		case 1:
			choisirUnMot(pt_nb_mot, mot);
			system("cls");
			jouer(mot);
			break;
		case 2:
			do
			{
				printf("\n\nQuel est le mot a faire deviner ? ");
				scanf("%s", mot_saisie);
				fflush(stdin);
				mot = &mot_saisie[0];
				strcpy(mot, mot_saisie);
				mot_correct = verifMot(mot); // On vérifie que le mot est correct (que des lettres minuscules ou majuscules et rien d'autre)
			} while (mot_correct != 1);


			system("cls");
			jouer(mot);
			break;
		case 3:
			menuEditerDictionnaire(pt_nb_mot);
			break;
		default :
			printf("\n\nMauvaise touche ! Veuillez taper 0, 1, 2 ou 3\n");
			break;
		}
		


	} while (choix != 0);

	return 0;
}
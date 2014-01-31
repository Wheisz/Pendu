#include<stdio.h>	
#include<stdlib.h>
#include <string.h>
#include"fonctions.h"
#include "fichier.h"


void editerDictionnaire(char *mot, int *pt_nb_mot)
{
	// ================== VARIABLES ========================= //
	FILE* fichier = NULL;
	int caractereActuel = 0, i = 0;

	
	// ================== INSTRUCTIONS ========================= //

	fichier = fopen("dictionnaire.txt", "a"); // On tente d'ouvrir dictionnaire.txt en mode ajout

	if (fichier != NULL)
	{
		// Si l'ouverture à fonctionnée

		fputs(mot, fichier); // On écrit le mot dans le dictionnaire
		fputs("\n", fichier);

		fclose(fichier);
	}
	else
	{
		// sinon on affiche un message d'erreur
		if (fichier == NULL)
		{
			printf("Impossible d'ouvrir le fichier fichier.txt");
		}
	}
}

void menuEditerDictionnaire(int *pt_nb_mot)
{
	// ================== VARIABLES ========================= //

	char* mot = NULL;
	char mot_saisie[100], continuer;
	int mot_correct;

	// ================== INSTRUCTIONS ========================= //
	do
	{
		printf("\n\nVeuillez ecrire le mot que vous voulez ajouter au dictionnaire : ");
		do
		{
			scanf("%s", mot_saisie);
			mot = &mot_saisie[0];
			strcpy(mot, mot_saisie);
			mot_correct = verifMot(mot); // On vérifie que le mot est correct (que des lettres minuscules ou majuscules et rien d'autre)
		} while (mot_correct != 1);

		editerDictionnaire(mot, pt_nb_mot); // On écrit le mot dans le fichier
		fflush(stdin);

		do
		{
			printf("\n\nVoulez vous ajouter un autre mot au dictionnaire ? (o/n)");
			printf("\nVotre choix : ");
			scanf("%c", &continuer);
			fflush(stdin);

			if (continuer != 'n' && continuer != 'o')
			{
				printf("\n\nErreur, veuillez utiliser o ou n");
			}
		} while (continuer != 'n' && continuer != 'o');
		
	} while (continuer == 'o');

}

void choisirUnMot(int *pt_nb_mot, char *pt_mot)
{
	// ================== VARIABLES ========================= //
	FILE* fichier = NULL;
	int caractereActuel = 0, compteur_retour_chariot = 0, random_mot = 0;
	int i = 0, nb_alea = (nombreAleatoire(*pt_nb_mot)) - 1;
	char mot_pas_pret[100];
	char *pt_mot_pas_pret = mot_pas_pret;
	int taille_mot;


	// ================== INSTRUCTIONS ========================= //

	fichier = fopen("dictionnaire.txt", "r+"); // On tente d'ouvrir dictionnaire.txt en mode lecture/écriture

	if (fichier != NULL)
	{
		// Si l'ouverture à fonctionnée

		rewind(fichier); // On place le curseur au début du fichier

		// Boucle pour place le curseur au n éme mot (fonction rand)
		do
		{
			caractereActuel = fgetc(fichier); // On lit le caractère

			if (caractereActuel == '\n')
			{
				compteur_retour_chariot++;

			}// On continue tant que fgetc n'a pas retourné EOF (fin de fichier) ou tant que l'on a pas atteint le nombre de mot (choisi par random)
		} while ((caractereActuel != EOF) && (compteur_retour_chariot != nb_alea)); 

		fgets(pt_mot, 100, fichier);
		taille_mot = strlen(pt_mot);
		EnleverFinMot(pt_mot, taille_mot);

		fclose(fichier);
	}
	else
	{
		// sinon on affiche un message d'erreur
		printf("Impossible d'ouvrir le fichier test.txt");
	}

	
}

int nombreAleatoire(int nombreMax)
{
	srand(time(NULL));
	return (rand() % nombreMax);
}

void nbMot(int *pt_nb_mot)
{
	// ================== VARIABLES ========================= //

	FILE* fichier = NULL;
	int nb_retour_chariot = 0, caracActuel = 0;


	// ================== INSTRUCTIONS ========================= //

	fichier = fopen("dictionnaire.txt", "r"); // On tente d'ouvrir dictionnaire.txt en mode lecture seule

	if (fichier != NULL)
	{
		// Si l'ouverture à fonctionnée

		rewind(fichier); // On place le curseur au début du fichier

		do
		{
			caracActuel = getc(fichier);

			if (caracActuel == '\n')
			{
				nb_retour_chariot++;
			}
		} while (caracActuel != EOF);

		*pt_nb_mot = nb_retour_chariot;
	}
	else
	{
		// sinon on affiche un message d'erreur
		printf("Impossible d'ouvrir le fichier test.txt");
	}
}

void EnleverFinMot(char *pt_mot, int taille_mot)
{
	int i = taille_mot;

	while (i > 0 && *(pt_mot + (i - 1)) == '\n')
	{
		i--;
		*(pt_mot + i) = '\0';
	}
}


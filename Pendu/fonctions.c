#include<stdio.h>	
#include<stdlib.h>
#include <string.h>
#include"fonctions.h"
#include "fichier.h"


void jouer(char* mot)
{
	// ================== VARIABLES ========================= //
	int nb_vie = 9, taille_mot = strlen(mot), gagner = 0;
	int i, caract_correct;
	char* pt_c = NULL;
	char c;
	char* mot_bis = malloc(taille_mot * sizeof(char));


	// ================== INSTRUCTIONS ========================= //

	cacher_mot(mot_bis, taille_mot);
	
	do
	{
		// Affichage du mot a deviner + nb vie
		printf("\n=============================");
		printf("\nVous avez %d vie(s)\n", nb_vie);
		printf("\nMot \x85 trouver : %s\n", mot_bis);	
		printf("\n=============================");

		// Demande à l'utilisateur de rentrer un caractere
		do
		{
			printf("\n\nVeuillez donner une lettre : ");
			scanf("%c", &c);
			fflush(stdin);
			pt_c = &c;
			caract_correct = verifCaract(pt_c);
		} while (caract_correct != 1);
		
		

		// On test cette lettre
		if (test(mot, c, mot_bis) == 1)
		{

			printf("\n\nBravo ! La lettre %c etait bien dans le mot : %s\n", c, mot_bis);
		}
		else
		{
			printf("\n\nNon ! La lettre %c n'est pas dans le mot : %s\n", c, mot_bis);
			nb_vie--;
		}

		gagner = motTrouve(mot_bis);

	} while (gagner != 1 && nb_vie != 0);

	if (nb_vie == 0)
	{
		printf("\n\nVous avez perdu !!!!!!\n");
		printf("\nLe mot a deviner etait : %s", mot);
	}
	if (gagner == 1)
	{
		printf("\n\nBravo ! Vous avez gagn\x82 !");
	}
}

/* On teste et si le caractère est dans le mot on remplace le _ par le caractère 
	return 1 si c'est dedans
	return 0 si pas dedans	*/
int test(char* mot, char c, char* mot_bis)
{
	int position = 0, trouve = 0;

	while (*(mot + position) != 0)
	{
		if (c == *(mot + position))
		{
			*(mot_bis + position) = c;
			trouve = 1;
		}
		position++;
	}
	if (trouve == 1)
	{
		return 1;
	}
	return 0;
}

char *cacher_mot(char *mot_bis, int taille_mot)
{
	for (int i = 0; i < taille_mot; i++)
	{
		*(mot_bis + i) = '\xB8';
	}
	*(mot_bis + taille_mot) = '\0';
	return mot_bis;
}

int motTrouve(char *mot_bis)
{
	int i = 0;

	while (*(mot_bis + i) != 0)
	{
		if (*(mot_bis + i) == '\xB8')
		{
			return 0;
		}
		i++; 
	}
	return 1;
}

int verifMot(char *mot) // Renvoi 1 si le mot est correct, 0 si incorrect
{
	int i = 0;

	while (*(mot + i) != 0)
	{
		if ((*(mot + i) >= 97) && (*(mot + i) <= 122)) //On transforme les minuscules en majuscules
		{
			*(mot + i) = (*(mot + i) - 32);
		}
		i++;
	}
	i = 0;
	while (*(mot + i) != 0)
	{
		if ((*(mot + i) < 65) || (*(mot + i) > 90)) //Si caractere pas bon message d'erreur et on retourne 0
		{
			printf("\nSeul les lettres minuscules ou les majuscules sont autoris\x82 pour ecrire un mot");
			printf("\n	- Pas d'accent\n	- Pas de caract\x8Are speciaux");
			return 0;
		}
		i++;
	}
	return 1;
}

int verifCaract(char *caract) // Renvoi 1 si le caractère est correct, 0 si incorrect
{
	if ((*caract >= 97) && (*caract <= 122)) //Si caractère en minuscule on le passe en majuscule
	{
		*caract = *caract - 32;
	}
	if ((*caract < 65) || (*caract > 90)) //Si caractere pas bon message d'erreur et on retourne 0
	{
		printf("\nSeul les caract\x8Are minuscules ou les majuscules sont autoris\x82 pour saisir une lettre");
		printf("\n	- Pas d'accent\n	- Pas de caract\x8Are speciaux");
		return 0;
	}
	return 1;
}

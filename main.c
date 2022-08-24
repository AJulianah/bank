#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct utilisateur
{
    char phone[50];
    char compte[50];
    char password[50];
    float balance;
}

main(int argc, char const *argv[])
{
    struct utilisateur usr;
    unsigned opt;
    FILE *fp;
    char filename[50];
    char phone[10];
    char password[10];

    printf("\nQue veus-tu faire ?");
    printf("\n\n1. Creer un compte");
    printf("\n\n2. Se connecter a un compte ");

    printf("\n\nEntrer votre choix: \t");
    scanf("%d", &opt);
    if (opt == 1)
    {
        #ifdef _WIN32
            system("cls");
        #elif __linux__
            system("clear");
        #endif
        printf("Entrer votre numero de compte : \t");
        scanf("%s", usr.compte);
        printf("Entrer votre numero telephone:\t");
        scanf("%s", usr.phone);
        printf("Entrer votre mot de passe: \t");
        scanf("%s", &usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w"); // On concatene filename avec .dat
        fwrite(&usr, sizeof(struct utilisateur), 1, fp);
        if (fwrite != NULL)
        {
            printf("\nCompte crée avec succes!");
        }
        else
        {
            printf("\nIl y a une erreur, veillez réessayer svp!");
        }
    }
    else if (opt == 2)
    {
        system("clear");
        printf("\nNumero telephone:\t");
        scanf("%s", &phone);
        printf("\nEntrer mot de passe:\n");
        scanf("%s", &password);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        fread(&usr, sizeof(struct utilisateur), 1, fp);
        if (!strcmp(password, usr.password))
        {
            printf("\n Les mot de passe sont les memes!");
        }
        else
        {
            printf("\nMot de passe invalide");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

#define NUM 65535 // 256*256

int *iniciarContador()
{
    return (int *) calloc(NUM, sizeof(int));
}

FILE *abrirArquivo(char *filename, char *mode)
{
    FILE *file;
    
    if (!(file = fopen(filename, mode)))
    {
        perror("Nao foi possivel abrir o arquivo");
        exit(-1);
    }

    return file;
}

void salvar(char *filename, int *contador)
{
    int i;

    FILE *file = abrirArquivo(filename, "w+");

    for (i = 0; i < NUM; i++)
    {
        fprintf(file, "%d\n", contador[i]);
    }

    fclose(file);
}

int main()
{
    int i;

    int *contador = iniciarContador();

    char filename[255];

    printf("Arquivo: ");
    scanf("%s", filename);

    FILE *file = abrirArquivo(filename, "r");

    while(!feof(file))
    {
        i = 0;
        fread(&i, 2, 1, file);
        contador[i]++;
    }

    fclose(file);

    printf("Saida: ");
    scanf("%s", filename);

    salvar(filename, contador);

    return 0;
}
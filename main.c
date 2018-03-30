#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("imagem.png", "rb");

    int i;

    int contador[65535];

    for (i = 0; i < 65535; i++)
    {
        contador[i] = 0;
    }

    int c;

    while(!feof(file))
    {
        fread(&c, 2, 1, file);
        contador[c] = contador[c] + 1;
    }

    fclose(file);

    file = fopen("saida.txt", "w+");

    for (i = 0; i < 65535; i++)
    {
        fprintf(file, "%d: %d\n", i, contador[i]);
    }

    fclose(file);

    return 0;
}

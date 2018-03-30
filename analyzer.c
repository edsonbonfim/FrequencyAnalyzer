/**
 * FrequencyAnalyzer
 *
 * The purpose of this code is to analyze how often integer
 * values (consecutive bytes) appear in files of various formats.
 *
 * @author   Edson Onildo <inbox.edsononildo@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 65535 // 256*256

int *startCounter()
{
    return (int *) calloc(NUM, sizeof(int));
}

FILE *openFile(char *filename, char *mode)
{
    FILE *file;
    
    if (!(file = fopen(filename, mode)))
    {
        perror("Could not open file");
        exit(-1);
    }

    return file;
}

void saveResponse(char *filename, int *counter)
{
    int i;

    FILE *file = openFile(filename, "w+");

    for (i = 0; i < NUM; i++)
    {
        fprintf(file, "%d\n", counter[i]);
    }

    fclose(file);
}

int *analyze(char *filename)
{
    FILE *file = openFile(filename, "r");
    
    int i, *response = startCounter();

    while(!feof(file))
    {
        i = 0;
        fread(&i, 2, 1, file);
        response[i]++;
    }

    fclose(file);

    return response;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: %s <input-file> <output-file>\n", argv[0]);
        return -1;
    }

    int *response = analyze(argv[1]);
    saveResponse(argv[2], response);

    return 0;
}

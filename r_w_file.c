#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getLineOfFile(FILE *file)
{
    int num = 0;
    char buffer[1024];
    while (fgets(buffer,1024,file) != NULL)
    {
        num++;
    }
    fseek(file, 0, SEEK_SET);
    return num;
}


void readFile(FILE *file, char **data)
{
    char buffer[1024];
    int i = 0;
    while (fgets(buffer, 1024, file) != NULL)
    {
        int currentLen = strlen(buffer);
        *(data + i) = (char *)malloc(sizeof(char) * currentLen);
        strcpy(*(data+i), buffer);
        //memset(buffer, 0, 1024);
        i++;
    }
}

void show(char **data, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%s", *(data+i));
    }
}


void test01()
{
    FILE *file = fopen("test.txt","r");
    if (file == NULL) {
        printf("File open failed\n");
    }
    int numLines = getLineOfFile(file);
    // printf("%d\n", numLines);
    char **data = (char **)malloc(sizeof(char*)*numLines);
    readFile(file, data);
    show(data, numLines);
}

int main()
{
    test01();
    return 0;
}
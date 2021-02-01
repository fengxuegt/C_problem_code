#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(show)
void testFile_c()
{
    FILE *file = fopen("./testc.txt", "w");
    if (file == NULL) {
        return;
    }
    char buffer[] = "hello file test.\nakjglkahg";
    int i = 0;
    while (buffer[i] != '\0')
    {
        fputc(buffer[i], file);
        i++;
    }
    fclose(file);

    FILE *read = fopen("./testc.txt", "r");
    if (read == NULL)
    {
        return;
    }
    char ch;
    while ((ch = fgetc(read)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(read);
}

void testFile_s()
{
    FILE *file = fopen("./tests.txt", "w");
    if (file == NULL) {
        return;
    }
    char * buffer[] = {
        "hello file test.\n",
        "akjglkahg\n",
        "jjjjjjjjjk\n"
    };
    int i = 0;
    while (i < 4)
    {
        fputs(buffer[i], file);
        i++;
    }
    fclose(file);

    FILE *read = fopen("./tests.txt", "r");
    if (read == NULL)
    {
        return;
    }
    while (!feof(read))
    {
        char temp[1024] = {0};
        fgets(temp, 1024, read);
        printf("%s", temp);
    }
    fclose(read);
}
struct person
{
    char name[64];
    int age;
};
void testFile_b()
{
    FILE *file = fopen("testb.txt", "wb");
    struct person p[] = {
        {"feng", 14},
        {"xue", 13},
        {"lw", 24}
    };
    for (int i = 0; i < 3; i++) {
        fwrite(&p[i], sizeof(struct person), 1, file);
    }
    fclose(file);

    FILE *read = fopen("testb.txt", "rb");
    //address, size of block, num of block, file pointer
    //struct person pesons[3];
    //fread(&person, sizeof(struct person), 3, read); //read 3 persons once!!!! 
    for (int i = 0; i < 3; i++)
    {
        struct person temp;
        fread(&temp, sizeof(struct person), 1, read);
        printf("%s ; %d\n", temp.name, temp.age);
    }
    fclose(read);  
}
int main()
{
    //testFile_c();
    //testFile_s();
    testFile_b();
    return 0;
}
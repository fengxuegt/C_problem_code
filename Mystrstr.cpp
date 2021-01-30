#include <stdio.h>
#include <stdlib.h>



int  kmp(const char * str, const char *target)
{
    int count = 0;
    char* p = (char *) str;
    char* cur = (char*)target;
    char* tmp = NULL;
    while (*p != '\0') {
        tmp = p;
        if (*p == *cur) {
            while (*cur != '\0')
            {
                if (*tmp != *cur) {
                    cur = (char*) target;
                    break;
                }
                cur++;
                tmp++;
            }
            if (*cur == '\0') {
                return count;
            }

        }
        p++;
        count++;
    }
    return -1;
}

int main()
{
    const char *str = "kajflkdnfkwej";
    const char* target = "kz";
    int result = kmp(str, target);
    
    if (result == -1) {
        printf("Not found.\n");
    }
    else {
        printf("The index is %d\n", result);
    }
    
    return 0;
}



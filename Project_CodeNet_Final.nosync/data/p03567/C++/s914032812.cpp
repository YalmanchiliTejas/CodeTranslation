#include <stdio.h>
#include <string.h>
char s[10];
int main(){
    scanf("%s", s);
    for (int i = 0; i < strlen(s) - 1; ++i){
        if (s[i] == 'A' && s[i+1] == 'C'){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
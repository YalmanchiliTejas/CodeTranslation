#include <stdio.h>
int main() {
    char S[4];
    scanf("%s", &S);
    if(S[0] != S[1]) {
        printf("Yes");
    }
    else if (S[1] != S[2]){
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}
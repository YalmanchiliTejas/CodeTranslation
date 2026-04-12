#include <stdio.h>
int main () {
    char S[100];
    scanf("%s", S);
    for (int i = 1; S[i] != '\0'; i++) {
        if (S[i-1] == 'A' && S[i] == 'C') {puts("Yes"); return 0;}
    }
    puts("No");
}
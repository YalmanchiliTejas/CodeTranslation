#include <stdio.h>
int main() {
    int n,k;
    char s[11];
    scanf("%d\n",&n);
    scanf("%s\n",s);
    scanf("%d",&k);
    char moji=s[k-1];
    for (int i=0; i<n; i++) {
        if (s[i]!=moji) {
            s[i]='*';
        }
    }
    printf("%s",s);
    return 0;
}
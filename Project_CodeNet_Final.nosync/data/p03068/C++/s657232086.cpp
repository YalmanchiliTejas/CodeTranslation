#include <stdio.h>

int main(void){
    int n, k, i;
    char a[10];

    scanf("%d", &n);
    scanf("%s", a);
    scanf("%d", &k);

    for(i=0;i<n;i++){
        if(a[i] != a[k-1]){
            printf("*");
        }else{
            printf("%c", a[k-1]);
        }
    }

    printf("\n");

    return 0;
}
#include<stdio.h>

int main(void){
    int n;
    int j;
    int k;
    int c;
    int i;
    int count = 0;
    int hi[100];

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &hi[i]);
    }

    for(j = 0; j < n; j++){
        c = 0;
        for(k = 0; k <= j; k++){
            if(hi[j] >= hi[k]){
                c++;
            }
        }
        if(c == j + 1){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
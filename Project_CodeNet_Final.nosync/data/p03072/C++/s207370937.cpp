#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int h[n];
    int res = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", h+i);
        int cansee = 1;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]){
                cansee *= 0;
            }
        }
        res += cansee;
    }
    printf("%d\n", res);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, k, x, y, i, ans=0, high=0;
    scanf("%d", &n);
    int h[n];
    for(i=0; i<n; i++) scanf("%d", &h[i]);

    for(i=0; i<n; i++){
        if(h[i]>=high){
            ans++;
            high = h[i];
        }
    }
    printf("%d", ans);
}
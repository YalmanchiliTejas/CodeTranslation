#include <stdio.h>
#include <math.h>


int main(void)
{
    int n;
    scanf("%d", &n);
    int h[n];
    for(int i=0; i < n; i++){
        scanf("%d", &h[i]);
    }

    int max = h[0];
    int cnt = 1;
    for(int i=1; i < n; i++){
        if(max <= h[i]){
            cnt++;
            max = h[i];
        }
    }


    printf("%d\n", cnt);
    
    return 0;
} 


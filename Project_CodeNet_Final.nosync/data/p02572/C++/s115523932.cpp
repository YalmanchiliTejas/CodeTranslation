#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    long long int i, j, n, x, ans=0, po=0;
    scanf("%lld", &n);
    long long int a[n], suma[n];
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    suma[0] = a[0];
    for(i=1; i<n; i++) suma[i] = suma[i-1] + a[i];
    for(i=0; i<n; i++) suma[i] = suma[i]%1000000007;
    for(i=0; i<n-1; i++){
        ans += a[i]*((suma[n-1]-suma[i]+1000000007)%1000000007);
        ans = ans%1000000007;
    }
    printf("%lld", ans);
}
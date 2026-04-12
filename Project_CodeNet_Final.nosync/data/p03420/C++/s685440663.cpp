#include <stdio.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    long long ans = 0;
    if (k == 0){
        printf("%lld\n", 1ll*n*n);
        return 0;
    }
    for (int b = k+1; b <= n; ++b){
        int t = n/b, r = n%b;
        ans += t*(b-k)+(r>=k?r-k+1:0);
    }
    printf("%lld\n", ans);
}
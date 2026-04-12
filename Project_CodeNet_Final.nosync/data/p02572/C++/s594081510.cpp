#include <bits/stdc++.h>
#define LL long long
LL module = 1000000007;
int main(){
    int N;
    scanf("%d", &N);

    LL sum = 0, ans=0;
    LL val;
    while(N--){
        scanf("%lld", &val);
        LL tmp = val*sum;
        tmp %= module;
        ans += tmp;
        ans %= module;
        sum += val;
        sum %= module;
    }   
    
    printf("%lld\n", ans);
    return 0;
}

#include<bits/stdc++.h>
const int md = 1e9+7;
int n[2], k;
long long a = 1, b = 1, ans;

int main(){
    scanf("%d%d%d", n, n+1, &k);
    for(int i = 1; i <= k-2; i++){
        a = a * (n[0] * n[1] - 1 - i) % md;
        b = b * i % md;
    }
    for(int i = md-2; i; i/=2){
        if(i&1) a = a * b % md;
        b = b * b % md;
    }
    for(int i = 0; i < 2; i++){
        b = a * n[i] % md * n[i] % md;
        for(int j = 1; j < n[i^1]; j++) ans += b * j % md * (n[i^1]-j) % md;
    }
    printf("%lld\n", ans % md);
}
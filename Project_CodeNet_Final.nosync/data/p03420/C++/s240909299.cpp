#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
ll r;

int main(){
    scanf("%d%d", &n, &k);
    if(!k){ printf("%lld\n", 1LL * n * n); return 0; }
    for(int i = k + 1; i <= n; i++){
        r += n / i * (i - k) + max(0, n % i + 1 - k);
    }
    printf("%lld\n", r);
}
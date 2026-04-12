#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL X, D[60];

LL f(int lv, LL k){
    if (k <= 0) return 0;
    LL r = (D[lv] - 1) / 2;
    if (k >= D[lv]) return (1ll << (lv+1)) - 1;
    if (k <= r) return f(lv-1, k-1);
    if (k == r+1) return 1ll << lv;
    return (1ll << lv) + f(lv-1, k-r-1);
}

int main(){
    scanf("%d %lld", &N, &X);
    D[0] = 1;
    for (int i=1; i<=N; i++) D[i] = 2*D[i-1] + 3;
    printf("%lld\n", f(N, X));
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 MOD = 1e9 + 7;

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

i64 multi_inv(i64 a, i64 md) {
    i64 x, y;
    extgcd(md, a, x, y);
    return (y > 0 ? y : md + y);
}

int main(){
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 comb = 1;
    for(i64 i=0;i<k-2;++i){
        comb *= (n*m-2)-i;
        comb %= MOD;
    }
    i64 denominator = 1;
    for(i64 i=k-2;i>0;--i){
        denominator *= i;
        denominator %= MOD;
    }
    comb *= multi_inv(denominator, MOD);
    comb %= MOD;
    i64 xsum = 0;
    for(i64 d=1;d<n;++d){
        xsum += (d*((n-d)*m % MOD) % MOD)*m % MOD;
        xsum %= MOD;
    }

    i64 ysum = 0;
    for(i64 d=1;d<m;++d){
        ysum += (d*((m-d)*n % MOD) % MOD)*n % MOD;
        ysum %= MOD;
    }

    cout << (xsum + ysum % MOD) * comb % MOD << endl;

    return 0;
}

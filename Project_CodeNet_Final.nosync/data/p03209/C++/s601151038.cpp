#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll patti(ll l)
{
    ll n = 1;
    for(ll i = 0;i < l;i++) {
        n = 2*n + 1;
    }
    return n;
}
ll vans(ll l)
{
    ll n = 0;
    for(ll i = 0;i < l;i++) {
        n = 2*n + 2;
    }
    return n;
}

ll eat(ll x, ll n)
{
    ll re = 0;
    if(x == 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }

    // 一番下のバンズを食べる
    if(0 < x) {
        x--;
    }

    // レベルn-1バーガーのサイズ
    ll v = vans(n - 1);
    ll p = patti(n - 1);

    // レベルn-1バーガーを食べる
    if(v + p <= x) {
        re += p;
        x -= v + p;
    }else{
        re += eat(x, n - 1);
        x = 0;
    }

    // 真ん中のパティを食べる
    if(0 < x) {
        x--;
        re++;
    }

    // レベルn-1バーガーを食べる
    if(v + p <= x) {
        re += p;
        x -= v + p;
    }else{
        re += eat(x, n - 1);
        x = 0;
    }

    // 一番上のバンズを食べる
    if(0 < x) {
        x--;
    }
    return re;
}

int main()
{
    ll N;
    ll X;
    scanf("%lld %lld", &N, &X);
    printf("%lld\n", eat(X, N));
    return 0;
}
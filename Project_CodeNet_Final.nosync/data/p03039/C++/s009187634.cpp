#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct mint{
    static const int MOD = 1000000007;

    long long v;

    mint() : v(0) {}
    mint(long long x){
        x = x % MOD;
        if(x < 0){ x += MOD; }
        v = x;
    }
    mint& operator+=(mint a){
        v += a.v;
        if(v >= MOD){ v -= MOD; }
        return *this;
    }
    mint& operator*=(mint a){
        v *= a.v;
        v %= MOD;
        return *this;
    }
    mint& operator/=(mint a){
        return (*this) *= a.inv();
    }

    mint operator*(mint a){
        return mint(v) *= a;
    }

    mint pow(long long k){
        mint res(1),tmp(v);
        while(k){
            if(k&1) res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    mint inv(){return pow(MOD - 2); }

    static mint comb(long long n, int k){
        mint res(1);
        for(int i = 0; i < k; ++i){
            res *= mint(n - i);
            res /= mint(i + 1);
        }
        return res;
    }
};

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    mint x(0);
    for(int d = 1; d < n; ++d){
        x += mint(d) * mint(n - d) * mint(m) * mint(m);
    }
    for(int d = 1; d < m; ++d){
        x += mint(d) * mint(m - d) * mint(n) * mint(n);
    }
    x *= mint::comb(n * m - 2, k - 2);
    printf("%lld\n", x.v);
    return 0;
}

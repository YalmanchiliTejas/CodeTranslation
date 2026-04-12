#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T>ostream &operator<<(ostream &o,const pair<T, T>&p)
{o<<"("<<p.first<<", "<<p.second<<")";return o;}

#define rep(i, n) for(lli i = 0; i < (lli)(n); i++)

const lli MOD = 1000000007LL;

lli modpow(lli a, lli n){
    lli res = 1;

    for(lli ai = a; n; n>>=1){
        if(1&n) res = (res*ai)%MOD;
        ai=(ai*ai)%MOD;
    }
    return res;
}

lli inv(lli n){
    return modpow(n, MOD-2);
}

lli modperm(lli n, lli k){
    lli res = 1;
    rep(i, k){
        res = (res*(n-i))%MOD;
    }
    return res;
}

lli modcomb(lli n, lli k){
    return (modperm(n, k)*inv(modperm(k, k)))%MOD;
}

lli posmod(lli n){
    lli res = n;
    res %= MOD;
    if(res < 0) res += MOD;
    return res;
}
int n, m;
int a[10];
int ai, bi;
bool path[10][10];
int res = 0;

int main(void){
    cin >> n >> m;
    rep(i,m){
        cin >> ai >> bi;
        path[ai][bi] = true;
        path[bi][ai] = true;
    }
    rep(i, n){
        a[i] = i+1;
    }
    res = 0;
    do{
        bool f = true;
        rep(i, n-1){
            if(path[a[i+1]][a[i]] == false) f = false;
        }
        if(f) res++;
    }while(next_permutation(a+1, a+n));
    cout << res << endl;
    return 0;
}

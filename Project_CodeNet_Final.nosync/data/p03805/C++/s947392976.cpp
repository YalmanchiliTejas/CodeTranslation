#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#define INF          1e9
#define INFLL        1e18
#define EPS          1e-9
#define MOD          998244353
#define REP(i,n)     for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)    for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)    for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)   for(ll i=(n);i>0;--i)
#define REPC(i,obj)  for(auto i:obj)
#define ALL(obj)     (obj).begin(),(obj).end()
#define SETP(n)      cout<<fixed<<setprecision(n)
#define VV(T,h,w)    move(vector<vector<T>>(h,move(vector<T>(w))))
#define VVI(T,h,w,i) move(vector<vector<T>>(h,move(vector<T>(w,i))))
using namespace std;
using ll = long long;
template<class T = ll>inline T in() { T ret; cin >> ret; return ret; }

int main()
{
    ll n = in(), m = in();
    set<pair<ll, ll>>pass;
    REP(i, m) {
        ll a = in(), b = in();
        pass.insert(make_pair(a, b));
        pass.insert(make_pair(b, a));
    }
    vector<ll>perm; for (ll i = 2; i <= n; ++i)perm.push_back(i);
    ll cnt = 0;
    do {
        perm.push_back(1);
        bool is_ok = true;
        REP(i, n - 1) is_ok &= pass.count(make_pair(perm[i], perm[i + 1])) == 1;
        if (is_ok)++cnt;
        perm.pop_back();
    } while (next_permutation(ALL(perm)));
    cout << cnt << endl;
}
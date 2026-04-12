#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#define INF          1e9
#define INFLL        1e18
#define EPS          1e-9
#define MOD          1000000007
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
    ll n = in();
    string s; cin >> s;
    ll k = in();
    REP(i, n) {
        cout << (s[i] != s[k - 1] ? '*' : s[i]);
    }
    cout << endl;
}
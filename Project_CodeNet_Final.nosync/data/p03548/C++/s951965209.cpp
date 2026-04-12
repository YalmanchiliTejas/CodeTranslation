#include "bits/stdc++.h"
using namespace std;
#define repi(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define rep(i,n) repi(i,0,n)
#define all(x) (x).begin(),(x).end()
#define tsort(v) sort((v).begin(), (v).end())
#define trev(v) reverse((v).begin(), (v).end())
#define siz(v) ((int)(v).size())
#define ers(v, n) (v).erase((v).begin() + n)
#define pop(v) (v).back(); (v).pop_back()
#define el "\n"
#define co(x) cout<<(x)<<el
#define coc(c, a, b) if(c)co((a));else co((b))
#define YES(c) coc(c,"YES", "NO")
#define Yes(c) coc(c,"Yes", "No")
#define yes(c) coc(c,"yes", "no")
#ifdef tqktmp_1
#define gc() getchar(); getchar()
#else
#define gc() 1
#endif
typedef long long lint;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    lint x,y,z;
    cin>>x>>y>>z;
    x-=z;
    co(x/(y+z));
}
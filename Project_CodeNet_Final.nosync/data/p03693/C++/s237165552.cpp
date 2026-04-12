#include"bits/stdc++.h"

#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)

using namespace std;
using ll = long long;
using pos = pair<ll, ll>;

ll r,g,b;

void solve();

int main() {

   solve();
   return 0;

}

void solve() {

    cin >>r>>g>>b;
    cout << ((10*g+b)%4==0?"YES":"NO") << endl;

}
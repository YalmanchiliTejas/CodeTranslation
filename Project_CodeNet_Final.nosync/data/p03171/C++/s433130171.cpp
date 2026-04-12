#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;


VL a;
vector<VVL> memo;
ll rec(int i, int l, int r) {  // [l, r)
    if(memo[i & 1][l][r] != LLONG_MAX) return memo[i & 1][l][r];
    if(r == l) return memo[i & 1][l][r] = 0;
    ll res;
    if((i & 1) == 0) 
        res = max(rec(i + 1, l + 1, r) + a[l], 
                  rec(i + 1, l, r - 1) + a[r - 1]);
    else 
        res = min(rec(i + 1, l + 1, r) - a[l], 
                  rec(i + 1, l, r - 1) - a[r - 1]);
    return memo[i & 1][l][r] = res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    memo.resize(2, VVL(n + 1, VL(n + 1, LLONG_MAX)));
    REP(i, n) cin >> a[i];
    cout << rec(0, 0, n) << ln;
    return 0;
}

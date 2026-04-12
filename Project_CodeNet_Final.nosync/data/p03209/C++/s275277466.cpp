#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
ll n,x;
ll L[55];
ll P[55];

ll solve(ll l, ll x) {
    ll ret = 0;
    // バーガー全部なら前計算の結果を返す
    if (L[l] == x) return P[l];
    
    // とりあえず下から見ていくが、一つ目はバンズなので食べたことにする
    x--;

    // まだx枚食べている途中なら(x>0なら)下半分のl-1レベルバーガーを食べられる分だけ食べてしまいましょう
    if (x > 0) {
        ll y = min(x,L[l-1]);
        ret += solve(l-1, y);
        // 食べた分xから引きます
        x -= y;
    }

    // まだx枚食べている途中なら(x>0なら)真ん中のパティを食べましょう
    if (x > 0) {
        ret++; x--;
    }

    // まだx枚食べている途中なら(x>0なら)上半分のl-1レベルバーガーを食べられる分だけ食べてしまいましょう
    if (x > 0) {
        ll y = min(x,L[l-1]);
        ret += solve(l-1, y);
        x -= y;
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    cin >> n >> x;
    memset(L,0,sizeof(L));
    memset(P,0,sizeof(P));
    L[0] = P[0] = 1ll;
    REP(i,50) L[i+1] = L[i]*2+3;
    REP(i,50) P[i+1] = P[i]*2+1;
    cout << solve(n,x) << endl;
    return 0;
}
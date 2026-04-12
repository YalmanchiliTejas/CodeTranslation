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


ll pat[52];
ll len[52];

ll solve(ll k, ll x) {
    if(len[k] == x) return pat[k];
    ll ans = 0;
    x--;
    if(x > 0) {
        ll L = min(x, len[k-1]);
        ans += solve(k-1, L);
        x-=L;
    }
    if(x > 0) {
        ans++;
        x--;
    }
    if(x > 0) {
        ll L = min(x, len[k-1]);
        ans += solve(k-1, L);
        x -= L;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    ll n, x;
    cin >> n >> x;
    len[0] = pat[0] = 1;
    for(int i = 0; i < 51; ++i){
        len[i+1] = 2*len[i]+3;
        pat[i+1] = 2*pat[i]+1;
    }
    ll ans = solve(n, x);
    cout << ans << std::endl;
    return 0;
}
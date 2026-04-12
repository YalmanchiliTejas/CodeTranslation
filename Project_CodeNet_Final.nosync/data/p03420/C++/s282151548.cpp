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

ll add (int i, int n, int k) {
    ll mod = 0ll;
    ll ret = (i-k)*(n/i)+max((n%i)-k+1, 0);
    if (k == 0) --ret;
    //cout << i << " " << ret << endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    ll ans = 0ll;
    for (int i = k+1; i <= n; ++i) {
        ans += add(i, n, k);
    }
    cout << ans << endl;
    return 0;
}
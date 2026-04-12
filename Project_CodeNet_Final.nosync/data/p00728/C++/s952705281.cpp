#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n,n) {
        vector<int> a(n);
        rep(i,n) cin>>a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 1; i < n-1; ++i) {
            ans += a[i];
        }
        cout << ans/(n-2) << endl;
    }
    return 0;
}

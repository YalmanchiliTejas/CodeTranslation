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
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> h(n);
    REP(i,n) {
        cin >> h[i];
    }
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < i; ++j) {
            if (h[j] > h[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
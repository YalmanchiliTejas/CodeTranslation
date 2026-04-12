#include <bits/stdc++.h>
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;
const int INF = 1e9;

int n;
int a[202020], ans[202020];

signed main()
{
    cin >> n;
    REP(i,n) {
        cin >> a[i];
    }

    reverse(a, a + n);
    int s = 0, t = n - 1;
    REP(i,n) {
        if (i % 2 == 0) {
            ans[s++] = a[i];
        } else {
            ans[t--] = a[i];
        }
    }

    REP(i,n) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}

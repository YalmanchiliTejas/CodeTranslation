#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e10;
const int MOD = 1e9 + 7;
#define dump(x) cout << #x << " = " << (x) << endl;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back
#define lb lower_bound
#define all(v) (v).begin(), (v).end()
#define P pair<int, int>
#define V vector<int>
#define M map<int, int>
#define S set<int>
#define itn int
#define tin int
#define tni int
bool dbg = false;
int N, a[100010];
V n;

void solve()
{
    FOR(i, 0, N)
    {
        auto it = lb(all(n), a[i]);
        if (it == n.begin()) {
            n.insert(it,a[i]);
        } else {
            it--;
            *it = a[i];
        }
    }
    cout << (int)n.size() << endl;
}

signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    FOR(i, 0, N)
    cin >> a[i];
    solve();
    return 0;
}

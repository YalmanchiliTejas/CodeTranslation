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
    /*auto LB = [&](int key) {
        int left = 0, right = n.size(), mid = 0;

        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (key <= vec[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };*/
    FOR(i, 0, N)
    {
        auto it = upper_bound(all(n), a[i] * -1);
        if (it == n.end()) {
            n.pb(a[i] * -1);
        } else {
            //it--;
            *it = a[i] * -1;
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

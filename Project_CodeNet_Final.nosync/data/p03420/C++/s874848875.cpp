#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    rep (b, k + 1, n + 1) {
        ll sum = (b - k);
        ll amari = n % b;
        if (amari >= k && amari < b) {
            sum += (n - amari) / b * (amari - k + 1) +
                   ((n - amari) / b - 1) * (b - amari - 1);
        } else {
            sum += (b - k) * ((n - k) / b);
        }
        if (k == 0) sum--;
        /*
        rep (i, k, b) {
            sum2 += (n - i) / b + 1;
            // cout << b << " " << sum << "\n";
        }
        cout << sum2 << " " << sum << "\n";
*/
        ans += sum;
    }
    cout << ans << "\n";
}
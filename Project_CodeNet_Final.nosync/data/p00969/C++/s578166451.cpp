#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));
    vector<vector<bool>> vis(N, vector<bool>(N));
    int ma = 2;
    rep(i, N) for (int j = i + 1; j < N; j++) if (!vis[i][j]) {
        int d = a[j] - a[i];
        int prev = i, t = 2;
        for (ll x = a[j]; ; x += d, t++) {
            int k = lower_bound(all(a), x) - a.begin();
            if (i < k && k < N && a[k] == x) {
                vis[prev][k] = true;
                prev = k;
                ma = max(ma, t);
            }
            else break;
        }
    }
    cout << ma << endl;
}


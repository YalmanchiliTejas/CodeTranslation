#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

struct box {
    ll item[3];
};

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> A(n);
    for(auto &x : A) {
        cin >> x;
    }
    if(n % 2 == 0) {
        if(n == 2) {
            cout << max(A[0], A[1]) << endl;
            return 0;
        }
        ll odd[n / 2 + 10] = {}, even[n / 2 + 10] = {};
        for(i = 1; i <= n; i++) {
            if(i % 2 == 0)
                even[i / 2] = A[i - 1];
            else
                odd[i / 2 + 1] = A[i - 1];
        }
        for(i = 0; i < n / 2 + 1; i++) {
            even[i + 1] += even[i];
            odd[i + 1] += odd[i];
        }
        ll ret = -INF;
        for(i = 0; i <= n / 2; i++) {
            ret = max(odd[i] + even[n / 2 + 1] - even[i], ret);
        }
        cout << ret << endl;
    } else {
        vector<box> v(n / 2 + 1);
        for(i = 1; i < n; i += 2) {
            v[i / 2] = {A[i - 1], A[i], A[i + 1]};
            //cout << i/2 << endl;
        }
        vector<vector<ll>> dp(n / 2 + 1, vector<ll>(3, -INF));
        function<ll(int, int)> dfs = [&](const int now, const int cnt) {
            if(now == n / 2 - 1) {
                return v[now].item[cnt];
            }
            if(dp[now][cnt] != -INF)
                return dp[now][cnt];
            else {
                ll tmp = -INF;
                for(int x = cnt; x <= 2; x++) {
                    tmp = max({v[now].item[cnt] + dfs(now + 1, x), tmp});
                }
                return dp[now][cnt] = tmp;
            }
        };

        ll ret = max({dfs(0, 0), dfs(0, 1), dfs(0, 2)});
        cout << ret << endl;
        //cout << v[n/2-1].item[2] << endl;
    }
    return 0;
}
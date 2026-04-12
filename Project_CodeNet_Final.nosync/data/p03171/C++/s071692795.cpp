#include <bits/stdc++.h>

typedef long long ll;
const ll MOD = 1000000007;

using namespace std;

int n;
vector<vector<vector<pair<ll, ll> > > > dp(3001, vector<vector<pair<ll, ll> > >(3001, vector<pair<ll, ll> >(2, {-1, -1})));
vector<int> a;

pair<ll, ll> ans(int l, int r, int p) {
    if (l == r) {
        if (p == 1) {
            return {(ll)a[l], 0LL};
        } else {
            return {0LL, (ll)a[l]};
        }
    } else if (dp[l][r][p].first != -1)
        return dp[l][r][p];
    auto t1 = ans(l + 1, r, 1 - p);
    auto t2 = ans(l, r - 1, 1 - p);
    if (p == 1) {
        t1.first += (ll)a[l];
        t2.first += (ll)a[r];
        dp[l][r][p] = max(t1, t2);
        return dp[l][r][p];
    } else {
        t1.second += (ll)a[l];
        t2.second += (ll)a[r];
        if (t1.second > t2.second) {
            dp[l][r][p] = t1;
        } else {
            dp[l][r][p] = t2;
        }
        return dp[l][r][p];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
        sum += (ll)temp;
    }
    auto temp = ans(0, n - 1, 1);
    cout << temp.first - temp.second;

    return 0;
}
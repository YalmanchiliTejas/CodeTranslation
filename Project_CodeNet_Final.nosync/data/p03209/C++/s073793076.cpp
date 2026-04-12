#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

ll sum[55], pcnt[55], bcnt[55];
ll rec (ll x, int i) {
    if (x == 0) return 0;
    if (x == 1) {
        if (i == 0) return 1;
        else {
            return 0;
        }
    }
    if (x > sum[i]) {
        return pcnt[i] + 1;
    } else if (x == sum[i]) {
        return pcnt[i];
    } else if (x > sum[i - 1] + 1) {
        return pcnt[i - 1] + rec (x - sum[i - 1] - 2, i - 1) + 1;
    } else {
        return rec (x - 1, i - 1);
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    ll ans = 0;
    rep (i, 0, n + 1) {
        pcnt[i] = 0;
        bcnt[i] = 0;
        sum[i] = 0;
    }
    pcnt[0] = 1, sum[0] = 1;
    rep (i, 0, n) {
        bcnt[i + 1] = bcnt[i] * 2 + 2;
        pcnt[i + 1] = pcnt[i] * 2 + 1;
        sum[i + 1] = pcnt[i + 1] + bcnt[i + 1];
    }
    cout << rec (x, n) << "\n";
}

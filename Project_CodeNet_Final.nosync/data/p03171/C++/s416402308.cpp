#define D(x) cout << #x " = " << x << endl
#define DD(x, y) cout << "(" #x ", " #y ") = (" << x << ", " << y << ")" << endl
#define DDD(x, y, z) cout << "(" #x ", " #y ", " #z ") = (" << x << ", " << y << ", " << z << ")" << endl
#define DV(v) for (auto __macro_vi : v){ cout << __macro_vi << " ";} cout << endl;
#define DA(a, n) for (int __macro_i = 0; __macro_i < n; ++__macro_i) { cout << a[__macro_i] << " "; } cout << endl;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(v) (v).begin(), (v).end()
#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<iomanip>

using namespace std;
using ll = long long;
int n;
vector<ll> a;
vector<vector<vector<ll>>> memo;

ll recv(int i, int j, int k) {
    if (i == j) return 0;
    if (memo[i][j][k] != -1) return memo[i][j][k];
    ll ans;
    int nk = k == 0 ? 1 : 0;
    if (k == 0) {
        ans = max(
            recv(i + 1, j, nk) + a[i],
            recv(i, j - 1, nk) + a[j - 1]
        );
    } else {
        ans = min(
            recv(i + 1, j, nk) - a[i],
            recv(i, j - 1, nk) - a[j - 1]
        );
    }
    memo[i][j][k] = ans;
    return ans;
}

int main()
{
    cin >> n;
    a.resize(n);
    memo = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
    REP(i, n) {
        cin >> a[i];
    }
    cout << recv(0, n, 0) << endl;

    // REP(i, n + 1) {
    //     REP(j, n + 1) {
    //         cout << setw(5) << memo[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // REP(i, n + 1) {
    //     REP(j, n + 1) {
    //         cout << setw(5) << memo[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
}

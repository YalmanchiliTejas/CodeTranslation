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

using namespace std;
const int INF = (1u << 31) - 1;
int lis(vector<int> &v) {
    int m = v.size();
    vector<int> dp(m + 1, INF);
    int lk = -1;
    REP(i, m) {
        int k = distance(dp.begin(), upper_bound(dp.begin(), dp.end(), v[i]));
        dp[k] = v[i];
        lk = max(k, lk);
    }
    return lk + 1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];
    reverse(v.begin(), v.end());
    cout << lis(v) << endl;
}

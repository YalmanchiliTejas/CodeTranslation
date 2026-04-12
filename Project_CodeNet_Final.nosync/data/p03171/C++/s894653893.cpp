/// hi_im_manh :D
#include <bits/stdc++.h>
#define reset(a,n) memset(a,0,(n+1)*sizeof(int))
#define endl "\n"
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define intmax INT_MAX
#define intmin INT_MIN
#define ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define duckman "TASK"

#define input freopen(duckman".inp", "r", stdin);
#define output freopen(duckman".out", "w", stdout);

#define nmax 1005
const ll INF = 1e18L + 5;
using namespace std;

void max_self(ll &a, ll b) {
    a = max(a, b);
}

void min_self(ll &a, ll b) {
    a = min(a, b);
}

const ll M = 1e9 + 7;

void add_self(int &a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

char a[nmax][nmax];
int main()
{
    fast;
//    input;
//    output;

//    ll n, weight;
//    cin >> n >> weight;
//    vector<ll> dp(weight+1);
//    for (int i = 0; i < n; ++i) {
//        ll v, w;
//        cin >> w >> v;
//        for (ll weight_now = weight; weight_now - w >= 0; --weight_now) {
//            max_self(dp[weight_now], dp[weight_now - w] + v);
//        }
//    }
//    cout << dp[weight];

//    ll n, weight;
//    cin >> n >> weight;
//    vector<ll> w(n), v(n);
//    ll sum_v = 0;
//    for (ll i = 0; i < n; i++) {
//        cin >> w[i] >> v[i];
//        sum_v += v[i];
//    }
//    vector<ll> dp (sum_v + 1, INF);
//    dp[0] = 0;
//    for (ll i = 0; i < n; ++i) {
//        for (ll value_now = sum_v; value_now >= v[i]; --value_now) {
//            min_self(dp[value_now], dp[value_now - v[i]] + w[i]);
//        }
//    }
//    for (ll i = sum_v; i >= 0; --i) {
//        if (dp[i] <= weight) {
//            cout << i;
//            return 0;
//        }
//    }

//    string x, y;
//    getline(cin, x);
//    getline(cin, y);
//    ll n = x.size(), m = y.size();
//    vector<vector<ll>> dp (n+2, vector<ll>(m+2));
//    for (ll i = 0; i <= n; i++) {
//        for (ll j = 0; j <= m; j++) {
//            if (i == 0 || j == 0) {
//                dp[i][j] = 0;
//            }
//            else {
//                if (x[i-1] == y[j-1]) {
//                    dp[i][j] = dp[i-1][j-1] + 1;
//                }
//                else {
//                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                }
//            }
//        }
//    }
//    string ans = "";
//    ll i = n, j = m;
//    while (i && j) {
//        if (x[i-1] == y[j-1]) {
//            ans = x[i-1] + ans;
//            --i;
//            --j;
//        }
//        else {
//            if (dp[i][j] == dp[i-1][j]) {
//                --i;
//            }
//            else {
//                --j;
//            }
//        }
//    }
//    cout << ans;

//    ll r, c;
//    cin >> r >> c;
//    char a[r][c];
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cin >> a[i][j];
//        }
//    }
//    ll dp[r+1][c+1];
//    memset(dp, 0, sizeof(dp));
//    dp[1][0] = 1;
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            if (a[i][j] == '.') {
//                dp[i+1][j+1] = (dp[i+1][j] % M + dp[i][j+1] % M) % M;
//            }
//            else {
//                dp[i+1][j+1] = 0;
//            }
//        }
//    }
//    cout << dp[r][c] % M;

//    ll row, col;
//    cin >> row >> col;
//    for (ll r = 0; r < row; ++r) {
//        cin >> a[r];
//    }
//    vector<vector<int>> dp (row, vector<int>(col));
//    dp[0][0] = 1;
//    for (int r = 0; r < row; ++r) {
//        for (int c = 0; c < col; ++c) {
//            for (int r2 : {r,r+1}) {
//                int c2 = c;
//                if (r2 == r) {
//                    ++c2;
//                }
//                if (c2 < col && r2 < row && a[r2][c2] == '.') {
//                    add_self(dp[r2][c2], dp[r][c]);
//                }
//            }
//        }
//    }
//    cout << dp[row-1][col-1];

//    ll n, c;
//    cin >> n >> c;
//    vector<ll> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    vector<ll> dp(n);
//    dp[0] = 0;
//    for (int i = 1; i < n; i++) {
//        dp[i] = llmax;
//        for (int j = 0; j < i; ++j) {
//            dp[i] = min(dp[i], dp[j] + c + (a[i]-a[j])*(a[i]-a[j]));
//        }
//    }
//    cout << dp[n-1];

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    // dp[i+1][j], dp[i][j-1]
    for (int i = n-2; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];

}

/*

*/

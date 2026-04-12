#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef map<ll, ll> mii;
const int MOD = 1e9 + 7;

#define fastIO() \
ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair 

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vi> dp(n, vi(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = a[i];
    for (int l = 2; l <=n; ++l) {
        for (int i = 0; i + l - 1 < n; ++i) {
            int j = i + l - 1;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;    
    return 0;
}

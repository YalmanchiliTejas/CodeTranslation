#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int> iii;
typedef vector<iii> viii;

#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define LSOne(x) (x & (-x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int iinf = 1e9+7;
const ll inf = 1e18+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vi v(n);
    for (auto& i : v) cin >> i;
    vector<vll> dp(n+1, vll(n+1,0));
    for (int i = n-1; i >= 0; --i)
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = v[i];
            } else {
                dp[i][j] = max(v[i] - dp[i+1][j],v[j] - dp[i][j-1]);
            }
        }
    cout << dp[0][n-1] << endl;
}

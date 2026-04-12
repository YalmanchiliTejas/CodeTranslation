#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vll a(n);
    rep(i,0,n) cin >> a[i];

    vector<vll> dp(n,vll(n,0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                dp[i][j] = a[i];
            } else {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}

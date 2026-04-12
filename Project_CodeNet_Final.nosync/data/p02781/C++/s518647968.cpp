#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[110][2][10];

int main() {
    string s; int k;
    cin >> s >> k;

    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int now = s[i] - '0';
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= 3; j++) {
                for (int x = 0; x <= (smaller ? 9 : now); x++) {
                    if (x == 0) {
                        dp[i+1][smaller || x < now][j] += dp[i][smaller][j];
                    }
                    if (x > 0) {
                        dp[i+1][smaller || x < now][j+1] += dp[i][smaller][j];
                    }
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl;
}

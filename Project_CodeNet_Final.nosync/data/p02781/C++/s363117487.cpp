#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll dp[110][2][4];

int main(){
    string n;
    cin >> n;
    int k;
    cin >> k;

    dp[0][0][0] = 1;
    for (int i = 0; i < n.size(); ++i) {
        int d = n[i] - '0';
        // from 0
        if (d == 0){
            for (int j = 0; j < 4; ++j) {
                dp[i+1][0][j] += dp[i][0][j];
            }
        }
        else{
            for (int j = 0; j < 3; ++j) {
                dp[i+1][0][j+1] += dp[i][0][j];
                dp[i+1][1][j+1] += dp[i][0][j] * (d-1);
            }
            for (int j = 0; j < 4; ++j) {
                dp[i+1][1][j] += dp[i][0][j];
            }
        }
        // from 1
        for (int j = 0; j < 3; ++j) {
            dp[i+1][1][j+1] += dp[i][1][j] * 9;
        }
        for (int j = 0; j < 4; ++j) {
            dp[i+1][1][j] += dp[i][1][j];
        }

    }
    cout << dp[n.size()][0][k] + dp[n.size()][1][k] << endl;
}
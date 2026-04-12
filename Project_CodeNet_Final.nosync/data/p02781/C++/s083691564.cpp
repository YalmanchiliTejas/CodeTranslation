#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

int main(){
    string s;
    cin >> s;
    int k, n = s.size();
    cin >> k;
    ll dp[110][2][110] = {0};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        int D = s[i] - '0';
        for(int j = 0; j < 2; j++){
            for(int x = 0; x < 110; x++){
                for(int d = 0; d <= (j ? 9 : D); d++){
                    dp[i+1][j || d < D][x + (d == 0)] += dp[i][j][x];
                }
            }
        }
    }
    cout << dp[n][0][n-k] + dp[n][1][n-k] << endl;
    return 0;
}

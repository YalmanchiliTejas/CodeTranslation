#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vvvd = vector<vector<vector<double>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pint = pair<int, int>;
using Graph = vvi;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

int dp[105][4][2];

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;

    dp[0][0][0] = 1;
    int L = s.size();
    rep(i, L) {
        rep(j, 4) {
            rep(k, 2) {
                int nd = s[i] - '0';
                rep(d, 10) {
                    int ni = i + 1, nj = j, nk = k;
                    if(d != 0) nj++;
                    if(nj > K) continue;
                    if(k == 0) {
                        if(d > nd) continue;
                        if(d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[L][K][0] + dp[L][K][1] << endl;

    return 0;
}
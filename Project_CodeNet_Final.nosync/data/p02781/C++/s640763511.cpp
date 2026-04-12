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

bool cmp(pint a, pint b) {return a.second < b.second;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int m;

ll solve(string n) {
    int L = n.size();

    vvvll dp(L + 1, vector<vector<ll>>(2, vector<ll>(L + 1, 0)));
    dp[0][0][0] = 1;

    for(int i = 0; i < L; i++) {
        int D = n[i] - '0';
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < L; k++) {

                for(int d = 0; d <= (j ? 9 : D); d++) {
                    if(d != 0) {
                        dp[i+1][j || (d < D)][k + 1] += dp[i][j][k];
                    } else {
                        dp[i+1][j || (d < D)][k] += dp[i][j][k];
                    }
                }

            }
        }
    }

    return dp[L][0][m] + dp[L][1][m];
}

int main() {
    string n;
    cin >> n;
    cin >> m;

    cout << solve(n) << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin >> S >> K;
    N = S.size();
    vector<mat> dp(N, mat(K + 1, vec(2, 0)));
    dp[N - 1][0][1] = 1;
    dp[N - 1][1][1] = S[0] - '1';
    dp[N - 1][1][0] = 1;
    Rreps(i, N, 1) {
        rep(j, K + 1) {
            rep(k, 2) {
                for (int n = 0; n <= (k ? 9 : S[N - i] - '0'); ++n) {
                    if (n != 0 && j + 1 <= K) {
                        dp[i - 1][j + 1][k | (n < S[N - i] - '0')] += dp[i][j][k];
                    } else if (n == 0) {
                        dp[i - 1][j][k | (n < S[N - i] - '0')] += dp[i][j][k];
                    }
                }
            }
        }
    }
    cout << dp[0][K][0] + dp[0][K][1] << endl;
    /*rep(k, 2) {
        Rrep(i, N) {
            rep(j, K + 1) {
                cout << dp[i][j][k] << ' ';
            }
            cout << endl;
        }
    }*/
}
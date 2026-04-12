#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    string N;
    int K;
    cin >> N >> K;
    int len = N.length();

    vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(2, vector<int>(K + 1, 0)));
    
    dp[0][0][0] = 1;

    rep(n, len) {
        int num = N[n] - '0';
        rep(smaller, 2) {
            rep(k, K+1) {
                rep(x, (smaller ? 10 : num + 1)) {
                    if (k != 3 || x == 0) {
                        dp[n+1][smaller || x < num][(x == 0) ? k : k+1] += dp[n][smaller][k];
                    }
                }
            }
        }
    }
    // cout << dp[2][1][1] << endl;
    cout << dp[len][0][K] + dp[len][1][K] << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 998244353;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

ll dp[3100][3100][3] = {0};

int main(){
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= s; j++) {
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l <= k; l++) {
                    (dp[i+1][j][k] += dp[i][j][l]) %= MOD;
                }
                dp[i+1][j][k] %= MOD;
            }

            if(j - a[i] >= 0) {
                if(j == a[i]) (dp[i+1][j][1] += dp[i][0][0]) %= MOD, (dp[i+1][j][2] += dp[i][0][0]) %= MOD;
                (dp[i+1][j][1] += dp[i][j-a[i]][1]) %= MOD;
                (dp[i+1][j][2] += dp[i][j-a[i]][1]) %= MOD;
            }
        }
    }
    cout << dp[n][s][2] << endl;
}

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


ll dp[101][2][10];
 
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int m; cin >> m;

    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, 2){
            rep(k, 4){
                int lim = j ? 9 : (s[i] - '0');
                for(int d=0; d<=lim; d++){
                    dp[i+1][j || d<lim][k + (d != 0)] += dp[i][j][k];
                }
            }
        }
    }

    ll ans = 0;
    ans += dp[n][1][m];
    ans += dp[n][0][m];

    cout << ans << endl;
}
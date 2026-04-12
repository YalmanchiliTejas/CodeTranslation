#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1 << 21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 桁DP

int dp[105][4][2];
/*
    dp[i][j][k] := iけためまで決めて、j個の非0を使って、
    k==0: そこまでの桁はnと一緒
    k==1: そこまでの桁はすでにn以下であることが確定
*/

int main(){
    string s;
     cin >> s;
     int n = s.size();
     int K;
     cin >> K;
     dp[0][0][0] = 1;
     rep(i, n)rep(j, 4)rep(k, 2){
         int nd = s[i] - '0';
         rep(d, 10){
             int ni = i+1, nj = j, nk = k;
             if (d!=0) nj++;
             if (nj>K) continue;
             if (k==0) {
                 if (d > nd) continue;
                 if (d < nd) nk = 1;
             }
             dp[ni][nj][nk] += dp[i][j][k];
         }
     }
     int ans = dp[n][K][0] + dp[n][K][1];
     cout << ans << endl;

    return 0;
}

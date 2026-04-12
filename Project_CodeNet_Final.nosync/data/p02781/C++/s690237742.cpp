#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int dp[105][4][2];

int main()
{
    string s; cin >> s;
    int K; cin >> K;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n) rep(j,4) rep(k,2) {
        int nd = s[i] - '0';
        rep(d,10){
            int ni = i+1, nj = j, nk = k;
            if(d != 0){
                if(j+1>K) continue;
                nj++;
            }
            if(k==0){
                if(d > nd) continue;
                if(d < nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}
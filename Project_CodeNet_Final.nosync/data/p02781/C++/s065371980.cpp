

#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;
int dp[105][4][2];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;
    rep(i, n)rep(j, 4)rep(k, 2) {
        int nd = s[i] - '0';
        rep(d, 10) {
            int ni = i+1, nj = j, nk = k;
            if (d != 0 ) nj++;
            if (nj > K) continue;
            if (k == 0) {
                if (d > nd) continue;
                if (d < nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;


}
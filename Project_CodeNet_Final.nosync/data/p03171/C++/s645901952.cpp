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

ll n;
ll a[3001];

// dp[i][j] :
//  ai+1からajでゲームをするときのX-Yの最大値
//  ただし、手番は「元のゲームを行ってその局面になった時の手番」とする
int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
    }
    ll dp[n+1][n+1];
    rep(i, n+1) rep(j, n+1) dp[i][j] = 0;
    for(int len = 1; len <= n; len++){
        for(int l = 0; l < n - len + 1; l++){
            int r = l + len;
            dp[l][r] = max(a[l]-dp[l+1][r], a[r-1] - dp[l][r-1] );
        }
    }


    cout << dp[0][n] << endl;

}
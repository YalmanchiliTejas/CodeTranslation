#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
int dp[110][4][2];

signed main(){
	//cout << fixed << setprecision(10);
	string s; cin >> s;
    int K; cin >> K;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,0,n)rep(j,0,4)rep(k,0,2){
        int x = s[i] - '0';//now
        rep(d,0,10){
            int ni = i+1 , nj = j , nk = k;
            if(d != 0) nj++;
            if(K < nj) continue;
            if(nk == 0){
                if(d > x) continue;
                if(d < x) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}


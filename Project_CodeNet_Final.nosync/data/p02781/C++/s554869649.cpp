#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
const int mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dp[105][4][2];

int main(){
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(b,2){
        int nd = s[i] - '0';
        rep(td, 10){
            int ni = i+1, nj = j, nb = b;
            if(td != 0) nj++;
            if(nj > k) continue;
            if(b == 0){
                if(nd > td) nb = 1;
                if(nd < td) continue;
            }
            dp[ni][nj][nb] += dp[i][j][b];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;
}

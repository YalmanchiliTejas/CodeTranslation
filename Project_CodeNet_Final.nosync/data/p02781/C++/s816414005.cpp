#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    string n; ll k; cin >> n >> k;
    ll N = sz(n);
    ll dp[N+1][k+1][2];
    string t = "";
    t.pb(n[0]);
    int c = stoi(t);
    dp[1][0][1] = 1;
    dp[1][0][0] = 0;
    dp[1][1][1] = c-1;
    dp[1][1][0] = 1;
    rep(i, 2, k+1){
        dp[1][i][0] = 0;
        dp[1][i][1] = 0;
    }
    rep(i, 2, N+1){
        rep(j, 0, k+1){
            string r = ""; r.pb(n[i-1]);
            int f = stoi(r);
            if(j == 0){
                dp[i][j][0] = 0;
                dp[i][j][1] = 1;
            }else{
                if(f == 0){
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = 9*dp[i-1][j-1][1] + dp[i-1][j][1];
                }else{
                    dp[i][j][0] = dp[i-1][j-1][0];
                    dp[i][j][1] = dp[i-1][j-1][1]*9 + dp[i-1][j][1] + dp[i-1][j][0] + (f-1)*dp[i-1][j-1][0];
                }
            }
        }
    }
    prtl(dp[N][k][0] + dp[N][k][1]);
}


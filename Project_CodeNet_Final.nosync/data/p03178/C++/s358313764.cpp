#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

const int MAX_N = 1e4+10;
const int MAX_D = 110;
ll dp[MAX_N][MAX_D][2];

int main(){
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    {
        int c = s[0] - '0';
        rep(j, c) {
            dp[0][j%d][0]++;
        }
        dp[0][c%d][1]++;
    }
    REP(i, 0, n-1) {
        int c = s[i+1] - '0';
        rep(j, d) {
            rep(k, 10) {
                (dp[i+1][(j+k)%d][0] += dp[i][j][0]) %= MOD;
                if(k < c) (dp[i+1][(j+k)%d][0] += dp[i][j][1]) %=MOD;
                if(k == c) (dp[i+1][(j+k)%d][1] += dp[i][j][1]) %= MOD;
            }
        }
    }
    cout << (dp[n-1][0][0] + dp[n-1][0][1] - 1 + MOD) % MOD << endl;
    return 0;
}
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

const int MAX_N = 5010;
int prv[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi x(n);
    rep(i, n) cin >> x[i];
    if(n == 2) {
        cout << 2 << '\n';
        return 0;
    }
    sort(all(x));
    rep(i, MAX_N) rep(j, MAX_N) {
        prv[i][j] = -1;
        dp[i][j] = 2;
    }
    REP(j, 1, n-1) {
        int i = j+1;
        int k = j-1;
        while(i < n) {
            while(k >= 0 && x[i] - x[j] > x[j] - x[k]) {
                --k;
            }
            if(k >= 0 && x[i] - x[j] == x[j] - x[k]) prv[i][j] = k;
            ++i;
        }
    }
    REP(i, 1, n) rep(j, i) {
        int k = prv[i][j];
        if(k == -1) continue;
        dp[i][j] = max(dp[i][j], dp[j][k]+1);
    } 
    int ans = 0;
    rep(i, n) rep(j, i) ans = max(ans, dp[i][j]);
    cout << ans << '\n';
    return 0;
}

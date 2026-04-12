
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 998244353
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const double PI=acos(-1);
const double EPS=1e-9; //うまくいかなかったらゆるめる

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}

int dp[3005][3005] = {};

signed main(void) {
    int n,s;
    cin >> n >> s;
    vi a(n);
    rep(i,n)cin >> a[i];
    rep(i,n){
        dp[i][0] = i+1;
        dp[i+1][a[i]] += dp[i][0];
        dp[i+1][a[i]] %= MOD;
        loop(j,1,s+1){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if(j+a[i] <= s)dp[i+1][j+a[i]] += dp[i][j],dp[i+1][j+a[i]] %= MOD;
        }
    }
    //rep(i,n+1)rep(j,s+1)cout << i << " " << j << " " << dp[i][j] << endl;
    //cout << dp[n][s] << endl;
    int ans = 0;
    rep(i,n+1)ans += dp[i][s],ans %= MOD;
    cout << ans << endl;
}

// SeeAlso: https://atcoder.jp/contests/abc154/tasks/abc154_e
// https://atcoder.jp/contests/abc154/submissions/10009856

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000
#define NIL -1
#define MOD 1000000007

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define debug(x) cout<<#x<<": "<<x<<endl
#define debig_vec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

int k;
string n;


int main (){ 
    cin >> n;
    cin >> k;

    int l = n.size();

    ll dp[105][4][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 1;

    FOR(i, 1, l+1) {
        rep(j, k+1) {
		    if(n[i - 1] == '0'){
				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = dp[i - 1][j][1];
				if(j > 0){
					dp[i][j][1] += 9*dp[i - 1][j - 1][1];
				}
			}else if(j > 0){
				dp[i][j][0] = dp[i - 1][j - 1][0];
				dp[i][j][1] = 9*dp[i - 1][j - 1][1] + dp[i - 1][j][0] + dp[i - 1][j][1] + (n[i - 1] - '1')*dp[i - 1][j - 1][0];
			}else{
				dp[i][j][0] = 0;
				dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j][1];
			}
		}
    }

    ll ans = dp[l][k][0] + dp[l][k][1];
    print(ans);
    return 0;
}

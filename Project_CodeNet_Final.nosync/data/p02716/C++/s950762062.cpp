#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
#define debug(x) cerr << x << endl
#define Complex complex<double>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<59;
const ll mod = (int)1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i,n)cin >> a[i];
    ll dp[n][3];
    rep(i,n){
        rep(j,3)dp[i][j]=-INF;
    }
    rep(i,n){
        if(i==0)dp[0][0]=a[i];
        else if(i==1)dp[1][1]=a[i];
        else if(i==2){
            dp[2][2]=a[i];
            dp[2][0]=a[i]+dp[0][0];
        }
        else if(i==3){
            dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i]);
            dp[i][2]=max(dp[i-2][2]+a[i],dp[i-3][1]+a[i]);
        }
        else{
            dp[i][0]=dp[i-2][0]+a[i];
            dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i]);
            dp[i][2]=max({dp[i-2][2]+a[i],dp[i-3][1]+a[i],dp[i-4][0]+a[i]});
        }
      	//debug(dp[i][0]);
    }
  	/*rep(i,n){
      rep(j,3)cerr << dp[i][j] << ' ';
      cerr << endl;
    }*/
    if(n%2)cout << max({dp[n-3][0],dp[n-2][1],dp[n-1][2]});
    else cout << max(dp[n-2][0],dp[n-1][1]);
	
    


}

/*



 */



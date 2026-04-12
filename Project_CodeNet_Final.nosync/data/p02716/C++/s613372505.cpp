#include <bits/stdc++.h>
 
#define f(i,a,b) for( ll i = a; i < (ll) b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= (ll) b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
 
const int MAX= 1e6+100;

ll a[MAX],dp[MAX][3];

int main(){
	fastio;
	ll tc,n,b,x,k,q,l,r;
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	dp[0][0]=dp[0][2]=-1e18;
	dp[1][0]=-1e18;
	dp[1][2]=a[1];
	f(i,2,n+1) {
		if(i&1) f(j,0,3) dp[i][j]=max(dp[i-1][j],a[i]+dp[i-2][j]);
		else{
			f(j,0,2) dp[i][j]=max(dp[i-1][j+1],a[i]+dp[i-2][j]);
			dp[i][2]=a[i]+dp[i-2][2];
		}
	}
	cout<<dp[n][1]<<endl;
  	return 0;
}
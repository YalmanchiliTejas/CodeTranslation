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
 
const ll MAX= 3e3+100;

ll a[MAX],n,s,dp[MAX][MAX][3],mod=998244353;

int main(){
	fastio;
	cin>>n>>s;
	f(i,1,n+1) cin>>a[i];
	dp[0][0][0]=1;
	f(i,0,n){
		f(j,0,s+1){
			
			dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%mod;
			dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][0]+dp[i][j][1])%mod;
			dp[i+1][j][2]=(dp[i+1][j][2]+dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%mod;
		
			if(j+a[i+1]<=s) {
				dp[i+1][j+a[i+1]][1]=(dp[i+1][j+a[i+1]][1]+dp[i][j][0]+dp[i][j][1])%mod;
				dp[i+1][j+a[i+1]][2]=(dp[i+1][j+a[i+1]][2]+dp[i][j][0]+dp[i][j][1])%mod;
			}
			
		}
	}
	cout<<dp[n][s][2]<<endl;
  	return 0;	
}
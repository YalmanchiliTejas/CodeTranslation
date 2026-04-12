// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=110;
const ll mod=1e9+7;

ll dp[maxn][maxn],a[maxn];

ll tavan(ll a,ll b){
    ll an=1;
    while(b>0){
	if(b%2) an=(an*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return an;
}

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    a[0]=1;
    dp[0][0]=1;
    FOR(i,1,n){
	FOR(j,0,n){
	    if(a[j]<=a[i]){
		if(a[j]>=a[i-1]){
		    dp[i][j]=((2*dp[i-1][i-1])*tavan(2,max(ll(0),a[i]-a[j])))%mod;
		}
		else{
		    dp[i][j]=((dp[i-1][j]+dp[i-1][((a[i]>=a[i-1])?(i-1):(i))])*tavan(2,max(ll(0),a[i]-a[i-1])))%mod;
		}
	    }
	}
    }
    cout<<dp[n][0];
}

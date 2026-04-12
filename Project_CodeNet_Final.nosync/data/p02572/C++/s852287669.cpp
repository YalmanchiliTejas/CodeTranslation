#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size() 
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define ford(i,n) for(int i=n;i>=0;i--) 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define foreach(itr,c) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define fill(a,b) memset(a,b,sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi > vpi; 
ll mod=1000000007;
int main(){
	int n;
	cin>>n;
	ll a[n];
	ll sum[n];
	rep(i,n){
		cin>>a[i];
	} 
	fill(sum,0);
	for(int i=n-1;i>=0;i--){
		if(i==n-1){
			sum[i]=a[i]%mod;
		}
		else{
			sum[i]=(sum[i+1]+a[i])%mod;
		}
	}
	ll ans=0;
	rep(i,n-1){
		ans=(ans+a[i]*sum[i+1])%mod;
	}
	cout<<ans;
	re 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll N=2e5+5;
const ll MOD=1e9+7;
const ld pi=3.14159265359;
const ll INF=(1LL<<60);
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define setp setprecision
#define lwb lower_bound
#define SZ(a) (ll)a.size()

ll n,k,ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(ll b=k+1;b<=n;b++){
		ll tn=n,tmp=0;
		if(tn%b==0){
			ans+=(tn/b)*(b-k);
		}else if(tn%b>=k){
			ans+=tn%b-k+1;
			tn-=tn%b;
			ans+=(tn/b)*(b-k);
			if(k==0)ans--;
		}else{
			tn-=tn%b;
			ans+=(tn/b)*(b-k);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

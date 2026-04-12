// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;


int main(){	
	ll n,k;cin>>n>>k;
	ll ans=n*(n-k);
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	// no contar a=0
	for(ll b=k+1;b<n+1;b++){
		ll comp=(n+1)/b;
		ll taminc=(n+1)%b;
		ans-=k*comp;
		ans-=min(k,taminc);
		ans++;
	}
	cout<<ans<<endl;

	return 0;
}

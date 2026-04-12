#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 998244353;
const ll INF = 1e18;
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(),v.end()

int main(){
	ll n, x, m; cin >> n >> x >> m;
	VI f(m,-1),s(m,0);
	ll a=x,sum=0,ans=-1;
	REP(i,n){
		if(f[a]>=0){
			ans=(sum-s[f[a]])*((n-f[a])/(i-f[a]))+s[(n-f[a])%(i-f[a])+f[a]];
			break;
		}
		if(a==0){
			break;
		}
		f[a]=i;
		sum+=a;
		s[i+1]=sum;
		a=a*a%m;
	}
	if(ans==-1)
		ans=sum;
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
// please, read the question correctly (do you need set or multiset)???
const int N=200010; //check the limits, dummy
ll n, m, x;
ll trakm[N], l[N];
int main(){
	scanf("%lld%lld%lld",&n,&x,&m);
	trakm[1]=x;
	ll ans=x;
	ll tmp = x;
	for(ll i=2; i<=n; ++i){
		tmp = tmp*tmp%m;
		ans+=tmp;
		if(l[tmp]){
			trakm[i]=trakm[i-1]+tmp;
			ll period = i - l[tmp];
			ll sum = trakm[i]-trakm[l[tmp]];
			ll tmp1 = (n-i)/period;
			ll rem = (n-i)%period;
			ll sm1 = trakm[l[tmp]+rem]-trakm[l[tmp]];
			ans += sm1+sum*tmp1;
			break;
		}
		l[tmp] = i;
		trakm[i]=trakm[i-1]+tmp;
	}
	cout<<ans<<endl;
}
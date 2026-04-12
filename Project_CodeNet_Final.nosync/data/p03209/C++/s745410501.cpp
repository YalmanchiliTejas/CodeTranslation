#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 2147483647;
const ll LINF = 9223372036854775807;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	ll n, x; cin >> n >> x;
	VI p(n+1); p[0]=1;
	REP(i,n) p[i+1]=p[i]*2+1;
	VI a(n+1); a[0]=1;
	REP(i,n) a[i+1]=a[i]*2+3;
	ll ans=0;
	for(int i=n;i>0;i--){
		if(x>=a[i]){
			ans+=p[i];
			x-=a[i];
			if(x>=1){
				ans++;
				x--;
			}
		}
		x--;
	}
	x=max((ll)0,x);
	cout << ans+min((ll)3,x) << endl;
}
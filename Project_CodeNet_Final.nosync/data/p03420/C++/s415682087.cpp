#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PP;
typedef pair<ll,int> Pli;

//-----------------------------------------------------------------------------

ll n,k,ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>k;
	if(k==0) {
		cout<<n*n<<endl;
		return 0;
	}
	FOR(i,k+1,n+1) {
		ll a=(i-1)-(k-1);
		ll tmp=n/i;
		ll amari=n%i;
		amari-=(k-1);
		if(amari>=0) ans+=amari;
		ans+=a*tmp;
		//cout<<a<<' '<<tmp<<' '<<amari<<endl;
	}
	cout<<ans<<endl;

	return 0;
}

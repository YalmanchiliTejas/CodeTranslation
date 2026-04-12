#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(n) (n).begin(),(n).end()
#define fi first
#define se second
#define mset(x,v) memset((x),(v),sizeof(x))

typedef pair<int, int> PII;
typedef long long ll;

const int MOD = 1e9+7;
ll n,s,ans;
ll x,m;
ll val[200005];
map<ll, int> prv;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> m;
	int i=0;
	for (;i<n;i++) {
		
		if (prv.find(x)!=prv.end()) {
			break;
		}
		val[i]=x;
		ans+=x;
		prv[x]=i;
		x=(x*x)%m;
	}
	if (i<n) {
		n-=i;
		ll times = n/(i-prv[x]);
		ll k=0;
		for (int j=prv[x];j<i;j++) k+=val[j];
		ans+=k*times;
		n%=(i-prv[x]);
	} else {
		cout << ans << "\n";
		return 0;
	}
	for (i=0;i<n;i++) {
		ans+=x;
		x=(x*x)%m;
	}
	cout << ans << "\n";
}
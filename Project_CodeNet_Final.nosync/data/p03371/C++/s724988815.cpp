#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)

#define ALL(obj) (obj).begin(),(obj).end()

#define pii pair<int,int>

#define pb(a) push_back(a)
#define mp make_pair

int main()
{
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	if(a + b > 2 * c){
		int abBuy = min(x,y);
		ans += 2 * c * abBuy;
		x -= abBuy;
		y -= abBuy;
	}
	if(x > 0){
		if(a > 2 * c){
			ans += 2 * c * x;
		}else{
			ans += a * x;
		}
	}
	if(y > 0){
		if(b > 2 * c){
			ans += 2 * c * y;
		}else{
			ans += b * y;
		}
	}
	cout << ans << "\n";
	return 0;
}

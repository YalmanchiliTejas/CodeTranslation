#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define CLR(a) memset(a, 0, sizeof(a))
#define DBG(x) cout<<(#x)<<"="<<x<<endl
#define FOR(i, a, b)  for(int i=(a); i<(b); i++)
#define REP(i, a, b)  for(int i=(a); i<=(b); i++)
#define DOWN(i, a, b) for(int i=(a); i>=(b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const ll LL_INf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1000000009;
const int N= 1e5 +10;

ll n,k,tmp,ans;

int main(){
	cin>>n>>k;
	if (k==0) {
		cout<<n*n<<endl;
		return 0;
	} 
	REP(i, k+1, n) {
		ans+=n/(i)*(i-k);
		tmp=n-n/i*i;
		if (tmp>=k) ans+=tmp-k+1;
	}
	cout<<ans<<endl;
	//cout<<1.*clock()/CLOCKS_PER_SEC<<"ms"<<"\n";
	return 0;
}
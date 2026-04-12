#include <bits/stdc++.h>

using namespace std;
 
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef int64_t ll; typedef vector<int> VI; typedef pair<ll,ll> pii;
const ll mod = 1e9+7;

void dbg(){ cerr << "\n"; }  
template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
 	
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int a, b, c, x, y;
	cin >>a >>b >>c >>x >>y;
	
	ll ans = 1LL<<60;
	rep(i, max(x+1, y+1)){
		ll w = 2LL* i * c + max(x-i, 0) * (ll)a + max(y-i, 0) * (ll)b;
		ans = min(ans, w);
	}
	cout << ans <<"\n";
	return 0;
}

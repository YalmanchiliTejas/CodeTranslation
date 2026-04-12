#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll a,b,c,d,x,y;
	cin >>a >>b >>c >>x >>y;
	ll ans = a * x + b * y;
	rep(i, max(x,y)*2+1){
		ll na=max(0LL, x-i/2), nb=max(0LL, y-i/2);
		ll cnd = c*i;
		cnd += a*na + b*nb;
		ans = min(ans, cnd);
	}
	cout << ans <<"\n";
	return 0;
}

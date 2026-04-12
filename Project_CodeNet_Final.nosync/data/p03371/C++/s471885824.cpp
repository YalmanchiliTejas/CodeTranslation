#include <bits/stdc++.h>

using namespace std;
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } 
template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	//cin.tie(0); ios_base::sync_with_stdio(false);
	ll a,b,c,x,y;
	cin >>a >>b >>c >>x >>y;
	ll ans = a*x + b*y;
	VI ss;
	rep(i, x+y+1){
		
		ll w = max(0LL, a * (x-i)) + max(0LL,b* (y-i)) + max(0LL, c*i*2);
		
		ans = min(ans, w);
	
	}
	
	cout << ans <<"\n";
	return 0;
	
}

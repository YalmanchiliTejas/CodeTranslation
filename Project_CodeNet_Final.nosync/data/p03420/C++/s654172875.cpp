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
	

	int n, k;
	cin >>n >>k;
	
	
	/*ll zas =0;
	for(int i=1, j=1; i<=n; i++){
		for(j=1;j<=n;j++) if(j%i >=k) zas++;
	}
	cout << zas <<"\n";*/
	
	ll ans = 0;
	if(k==0){cout<<(ll)n*n <<"\n";return 0;}
	rep2(i,k+1,n+1){
		ll s=i-k;
		ans += (ll)n / i * s;
		ll amr = n%i;
		if( amr >= k) ans += amr+1-k;
	}
	cout << ans <<"\n";
	return 0;
}

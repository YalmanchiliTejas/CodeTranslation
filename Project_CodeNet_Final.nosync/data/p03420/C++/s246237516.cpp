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
	ll n,k;
	cin >>n >>k;
	
	if(k==0){cout <<n*n <<"\n"; return 0;}
	ll as=0;
	
	rep2(i,k+1,n+1){
		ll w= 1LL * (n /i ) * (i-k) + max(0LL, n%i +1LL -k);
		as += w;
		//dbg(i,i-k,n,w);
	}
	
	cout << as <<"\n";

	return 0;
	
}

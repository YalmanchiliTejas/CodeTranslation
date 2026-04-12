#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<ll> VI; typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	//cin.tie(0); ios_base::sync_with_stdio(false);
	

	string k; int d;
	cin >>k >>d;
	
	int n=sz(k); 
	vector<vector<ll> > p(d+2, vector<ll>(2));    
	p[0][0]=1;
	rep(i, n){
		vector<vector<ll> > np(d+2, vector<ll>(2));    
		
		rep(j, d) rep(s, 10){
			int mj = (j + s) % d;
			
			if(s < k[i] -'0') (np[mj][1] += p[j][0]) %=mod;
			else if(s== k[i] -'0') (np[mj][0] += p[j][0])%=mod;
			(np[mj][1] += p[j][1])%=mod;
			
			
		}
		swap(np, p);
	//for(auto x :p) printf("%d:%d, ",x[0], x[1]); puts("");
	}
	ll ans = (p[0][0] + p[0][1] -1 + mod) %mod;
	cout << ans <<"\n";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111
	ll mod = 1e9+7;

	void solve(){
		

		ini(n);
		vi a(n);
		vi a1(n,0);
		int tmp  = 0;
		FOR(i,0,n){
			in(a[i]);
			tmp+=a[i];
		}
		a1[n-1] = a[n-1];
		for (ll i1 = n-2; i1 >=0; i1--)
		{
			a1[i1]+=a[i1];
			a1[i1]+=a1[i1+1];
		}
		
		int tmp1 = 0;
		FOR(i,0,n){
			tmp1+=(a1[i]-a[i])%mod*a[i];
			tmp1%=mod;
		}
		FOR(i,0,n){
			// out(a1[i]);
		}
		out(tmp1%mod);
		
			
			
			


				
		


		
		
		
		

		


		
		
	}



	



















int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}

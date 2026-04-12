#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

//#pragma GCC target("avx2")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")

#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define ad push_back
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define make_unique(v) v.erase(unique(all(v)),v.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define srng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define y1 EsiHancagorcRepa

const int N=2e5+6;
const ll MOD=998244353;

ll k[N];
ll ans;
int main(){
	fastio;
	int n,s;
	cin>>n>>s;
	FOR(z,n){
		int tv;
		cin>>tv;
		k[0]++;
		FORD(i,s+1){
			if (i<tv)break;
			k[i]+=k[i-tv];
			k[i]%=MOD;
		}
		ans+=k[s];
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
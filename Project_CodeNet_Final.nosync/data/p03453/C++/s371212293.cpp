#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=5e5+500;
const ll inf=1e17+800;
const ll mod=1e9+7;

void jam(ll &a,ll b){a+=b;if(a>=mod)a-=mod;}
ll zarb(ll a,ll b){return (a*b)%mod;}

vector<ll> ger[maxn];
ll a[maxn];
ll b[maxn];
ll w[maxn];

ll minn[2][maxn];
ll dp[2][maxn];
ll dpyal[maxn];
ll dpp[maxn];

ll n,m;

void fillyal(ll s,ll t,ll fas){
	for(ll i=0;i<m;i++){
		if(minn[0][b[i]]+w[i]+minn[1][a[i]]==fas){
			swap(a[i],b[i]);
		}
		if(minn[0][a[i]]+w[i]+minn[1][b[i]]==fas && fas<minn[0][b[i]]*2 && minn[0][a[i]]*2<fas){
			dpyal[i]=zarb(dp[0][a[i]],dp[1][b[i]]);
		}
	}
}
void filldp(ll s,bool bo){
	dp[bo][s]=1;
	vector<pii> vec;
	for(ll i=1;i<=n;i++){
		vec.pb(mp(minn[bo][i],i));
	}
	sort(vec.begin(),vec.end());
	for(auto q:vec){
		ll v=q.S;
		for(auto e:ger[v]){
			if(minn[bo][v]==w[e]+minn[bo][a[e]^b[e]^v]){
				jam(dp[bo][v],dp[bo][a[e]^b[e]^v]);
			}
		}
	}
}
void diks(ll s,bool bo){
	for(ll i=0;i<maxn;i++)minn[bo][i]=inf;
	set<pii> st;
	st.insert(mp(0,s));
	while(st.size()){
		pii q=(*st.begin());
		st.erase(q);
		ll v=q.S;
		ll W=q.F;
		if(minn[bo][v]==inf){
			minn[bo][v]=W;
			for(auto e:ger[v]){
				st.insert(mp(W+w[e],a[e]^b[e]^v));
			}
		}
	}
}
int main(){
	ll s,t;
	cin>>n>>m>>s>>t;
	for(ll i=0;i<m;i++){
		cin>>a[i]>>b[i]>>w[i];
		ger[a[i]].pb(i);
		ger[b[i]].pb(i);
	}
	diks(s,0);
	diks(t,1);
	ll fas=minn[0][t];
	filldp(s,0);
	filldp(t,1);
	fillyal(s,t,fas);


	ll sum=dp[0][t];
	for(ll i=1;i<=n;i++){
		if(minn[0][i]+minn[1][i]==fas && minn[0][i]==minn[1][i]){
			dpp[i]=zarb(dp[0][i],dp[1][i]);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(minn[0][i]+minn[1][i]==fas && minn[0][i]==minn[1][i]){
			jam(ans,zarb((sum-dpp[i]+mod)%mod,dpp[i]));
		}
	}
	for(ll i=0;i<m;i++){
		jam(ans,zarb(dpyal[i],(sum-dpyal[i]+mod)%mod));
	}
	cout<<ans;


}



















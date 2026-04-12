#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <utility>
#include <memory>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i,n) _rep2((i),0,(n))
#define _rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define fi first
#define se second
#define mkp make_pair
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

ll mainmain(int n, vector<pll> v){
	sort(ALL(v));
	if(n==1){
		return 0;
	}
	ll mn = INFL, mx = 0;
	int pmn = -1, pmx = -1;
	rep(i,n){
		if(mn > v[i].fi){
			mn = v[i].fi;
			pmn = i;
		}
		if(mx < v[i].se){
			mx = v[i].se;
			pmx = i;
		}
	}
	// cout<<mx<<" "<<pmx<<endl;
	// cout<<mn<<" "<<pmn<<endl;
	ll a = 0;
	ll b = INFL;
	if(pmn==pmx){
		v.erase(v.begin()+pmn);
	}
	else{
		a = v[pmx].fi;
		b = v[pmn].se;
		v.erase(v.begin()+max(pmn,pmx));
		v.erase(v.begin()+min(pmn,pmx));
	}
	sort(ALL(v));
	// cout<<v.size()<<endl;
	// ll aa = max(a,b), bb = min(a,b);
	ll aa = a, bb = b;
	a = aa;
	b = bb;
	// cout<<"ab "<<a<<" "<<b<<endl;
	rep(i,v.size()){
		maxs(a, v[i].fi);
		mins(b, v[i].se);
	}
	// cout<<"ab "<<a<<" "<<b<<endl;
	ll ans = (a-mn)*(mx-b);
	// cout<<"ans "<<ans<<endl;
	if(pmn == pmx || v.size()==0){
		return ans;
	}
	// cout<<a<<" "<<b<<endl;
	// aa = max(a,b), bb = min(a,b);

	a = max(aa,bb);
	b = min(aa,bb);
	// cout<<"ab "<<a<<" "<<b<<endl;
	vll wfi(v.size());
	ll tmx = 0;
	for(int i=wfi.size()-1; i>=0; i--){
		maxs(tmx, v[i].fi);
		wfi[i] = tmx;
	}
	rep(i,v.size()){
		ll l = min(b, v[i].fi);
		ll r = max(a, wfi[i]);
		// cout<<"r l "<<r<<" "<<l<<endl;
		mins(ans, (mx-mn)*(r-l));
		mins(b, v[i].se);
		maxs(a, v[i].se);
	}
	a = max(aa,bb);
	b = min(aa,bb);
	vll wse(v.size());
	rep(i,n) swap(v[i].fi, v[i].se);
	sort(ALL(v));
	rep(i,n) swap(v[i].fi, v[i].se);
	ll tmn = INFL;
	rep(i,wfi.size()){
		mins(tmn, v[i].se);
		wse[i] = tmn;
	}
	for(int i=wfi.size()-1; i>=0; i--){
		ll l = min(b, wse[i]);
		ll r = max(a, v[i].se);
		// cout<<"r l "<<r<<" "<<l<<endl;
		// cout<<"v[i] "<<v[i].fi<<" "<<v[i].se<<endl;
		mins(ans, (mx-mn)*(r-l));
		mins(b, v[i].fi);
		maxs(a, v[i].fi);
	}
	return ans;
}

ll solve(int n, vector<pll> v){
	ll ans = INFL;
	rep(i,1<<n){
		ll rmx = 0, rmn = INFL;
		ll bmx = 0, bmn = INFL;
		rep(j,n){
			ll a = v[j].fi, b = v[j].se;
			if(i&(1<<j)){
				swap(a,b);
			}
			maxs(rmx, a);
			mins(rmn, a);
			maxs(bmx, b);
			mins(bmn, b);
		}
		mins(ans, (rmx-rmn)*(bmx-bmn));
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    int n;
	cin>>n;
	// n = 10;
	vector<pll> v(n);
	rep(i,n){
		cin>>v[i].fi>>v[i].se;
		if(v[i].fi>v[i].se) swap(v[i].fi, v[i].se);
	}
	cout<<mainmain(n, v)<<endl;
	return 0;
	// srand(time(NULL));
	// while(1){
	// 	rep(i,n){
	// 		cin>>v[i].fi>>v[i].se;
	// 		// v[i] = pll(rand()%10, rand()%10);
	// 		if(v[i].fi > v[i].se) swap(v[i].fi, v[i].se);
	// 	}
	// 	if(mainmain(n,v)!=solve(n,v)){
	// 		cout<<mainmain(n,v)<<" "<<solve(n,v)<<endl;
	// 		rep(i,n) cout<<v[i].fi<<" "<<v[i].se<<endl;
	// 		return 0;
	// 	}
	//     // cout<<mainmain(n, v)<<endl;
	//     // cout<<solve(n, v)<<endl;
	// }
}
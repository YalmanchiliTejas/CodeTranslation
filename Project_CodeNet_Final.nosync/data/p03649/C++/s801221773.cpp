#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(long long i=(a);i<(b);++i)
#define per(i,a,b) for(long long i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

int main() {
	ll n;
	cin>>n;
	ll ans = 0;
	vector<ll> v;
	rep(i,0,n){
		ll a;
		cin>>a;
		v.pb(a);
	}
	while(1){
		sort(all(v));
		if(v[v.sz-1]<200)break;
		ll b = (v[v.sz-1]-100)/n;
		v[v.sz-1]-=n*b;
		rep(i,0,v.sz-1){
			v[i]+=b;
		}
		ans += b;
	}
	while(1){
		sort(all(v));
		if(v[v.sz-1]<n)break;
		v[v.sz-1]-=n;
		rep(i,0,v.sz-1){
			v[i]++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}




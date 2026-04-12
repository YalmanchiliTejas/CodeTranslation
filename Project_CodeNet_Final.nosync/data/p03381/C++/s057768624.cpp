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
#include <iomanip>
using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

ll d[200200];

int main() {
	ll n;
	cin>>n;
	vector<pair<ll,ll> > v;
	ll sum = 0;
	rep(i,0,n){
		ll a;
		cin>>a;
		v.pb(mp(a,i));
	}
	sort(all(v));
	ll a1 = v[v.sz/2-1].fi;
	ll a2 = v[v.sz/2].fi;
	rep(i,0,v.sz){
		if(i<v.sz/2){
			d[v[i].se]=a2;
		}
		else{
			d[v[i].se]=a1;
		}
	}
	rep(i,0,n){
		cout << d[i] << endl;
	}
	return 0;
}
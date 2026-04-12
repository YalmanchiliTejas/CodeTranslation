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
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;
 
#define MOD 1000000007

int main(){
	ll n;
	cin>>n;
	vector<pair<ll,ll> > v;
	rep(i,0,n){
		rep(j,i+1,n){
			string s;
			rep(k,0,n){
				if(k==i||k==j)s+="1";
				else s+="0";
			}
			cout << "?" << " " << s << endl;
			ll ans;
			cin>>ans;
			if(ans == 1){
				v.pb(mp(i,j));
			}
		}
	}
	cout << "! ";
	rep(i,0,v.sz){
		cout << "(" << v[i].fi << "," << v[i].se << ")";
		if(i!=v.sz-1)cout << " ";
	}
	cout << endl;
	return 0;
}



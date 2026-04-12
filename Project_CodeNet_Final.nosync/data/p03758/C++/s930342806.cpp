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
 
ll d[210][210];
 
int main(){
	ll n;
	cin>>n;
	clr(d,-1);
	rep(i,0,40){
		string s;
		rep(j,0,200){
			s += "0";
		}
		rep(j,0,5){
			s[i+j*40] = '1';
		}
		cout << "?" << " " << s << endl;
		ll ans1;
		cin>>ans1;
		if(ans1==0){
			rep(j,0,5){
				rep(k,j+1,5){
					d[i+j*40][i+k*40] = 0;
				}
			}
		}
	}
	rep(i,0,n){
		rep(j,i+1,n){
			if(d[i][j]!=-1)continue;
			string s1;
			rep(l,0,n){
				if(l==i||l==j)s1+="1";
				else s1+="0";
			}
			cout << "?" << " " << s1 << endl;
			ll ans1;
			cin>>ans1;
			if(ans1==1){
				d[i][j] = 1;
			}
			else{
				d[i][j] = 0;
			}
		}
	}
	cout << "! ";
	vector<pair<ll,ll> > v;
	rep(i,0,200){
		rep(j,i+1,200){
			if(d[i][j] == 1){
				v.pb(mp(i,j));
			}
		}
	}
	rep(i,0,v.sz){
		cout << "(" << v[i].fi << "," << v[i].se << ")";
		if(i!=v.sz-1)cout << " ";
	}
	cout << endl;
	return 0;
}
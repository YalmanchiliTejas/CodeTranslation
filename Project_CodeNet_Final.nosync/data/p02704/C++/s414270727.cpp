#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

typedef unsigned long long ull;

ull ans[505][505];
ll cnts[505][65];
ll cntt[505][65];


int main(){
	ll n; cin >> n;
	vector<ll> s(n),t(n);
	vector<ull> u(n),v(n);
	rep(i,n) cin >> s[i];
	rep(i,n) cin >> t[i];
	rep(i,n) cin >> u[i];
	rep(i,n) cin >> v[i];
	rep(i,n){
		rep(j,n){
			if(!s[i] && !t[j]) ans[i][j] = u[i] | v[j];
			if(!s[i] && t[j]){
				rep(k,64){
					if((u[i]>>k & 1ULL) && !(v[j]>>k & 1ULL)){
						puts("-1");
						return 0;
					}
				}
				ans[i][j] = u[i];
			}
			if(s[i] && !t[j]){
				rep(k,64){
					if((v[j]>>k & 1ULL) && !(u[i]>>k & 1LL)){
						puts("-1");
						return 0;
					}
				}
				ans[i][j] = v[j];
			}
			if(s[i] && t[j]) ans[i][j] = u[i] & v[j];
		}
	}
	rep(i,n){
		if(!s[i]) continue;
		ull tmp = 0;
		rep(j,n) tmp |= ans[i][j];
		if(u[i] != tmp){
			rep(j,n) if(!t[j]) ans[i][j] |= u[i] - tmp;
		}
	}
	rep(j,n){
		if(!t[j]) continue;
		ull tmp = 0;
		rep(i,n) tmp |= ans[i][j];
		if(v[j] != tmp){
			rep(i,n) if(!s[i]) ans[i][j] |= v[j] - tmp;
		}
	}


	rep(i,n){
		rep(j,n){
			rep(k,64) if(ans[i][j]>>k & 1ULL) cnts[i][k]++;
		}
	}

	rep(j,n){
		rep(i,n){
			rep(k,64) if(ans[i][j]>>k & 1ULL) cntt[j][k]++;
		}
	}
	
	// -----------------------------

	rep(i,n){
		if(!s[i]) continue;
		ull tmp = 0;
		rep(j,n) tmp |= ans[i][j];
		if(u[i] != tmp){
			puts("-1");
			return 0;
		}
	}

	rep(j,n){
		if(!t[j]) continue;
		ull tmp = 0;
		rep(i,n) tmp |= ans[i][j];
		if(v[j] != tmp){
			puts("-1");
			return 0;
		}
	}

	//-------------------------------

	rep(i,n){
		if(s[i]) continue;
		ull tmp = ans[i][0];
		rep(j,n) tmp &= ans[i][j];
		bool flag = false;
		rep(j,n){
			rep(k,64){
				if((u[i]>>k & 1ULL) || !(tmp>>k & 1ULL)) continue;
				if(cntt[j][k] >= 2 && (t[j] || !(v[j]>>k & 1ULL))){
					cntt[j][k]--;
					cnts[i][k]--;
					ans[i][j] -= 1ULL<<k;
					tmp -= 1ULL<<k;
				}
			}
			if(u[i] == tmp){
				flag = true;
				break;
			}
		}
		if(!flag){
			puts("-1");
			return 0;
		}
	}

	rep(j,n){
		if(t[j]) continue;
		ull tmp = ans[0][j];
		rep(i,n) tmp &= ans[i][j];
		bool flag = false;
		rep(i,n){
			rep(k,64){
				if((v[j]>>k & 1ULL) || !(tmp>>k & 1ULL)) continue;
				if(cnts[i][k] >= 2 && (s[i] || !(u[i]>>k & 1ULL))){
					cntt[j][k]--;
					cnts[i][k]--;
					ans[i][j] -= 1ULL<<k;
					tmp -= 1ULL<<k;
				}
			}
			if(v[j] == tmp){
				flag = true;
				break;
			}
		}
		if(!flag){
			puts("-1");
			return 0;
		}
	}

	// -----------------------------
	rep(i,n){
		ull tmp = s[i] ? 0ULL : ans[i][0];
		if(s[i]) rep(j,n) tmp |= ans[i][j];
		else rep(j,n) tmp &= ans[i][j];
		if(u[i] != tmp){
			puts("-1");
			return 0;
		}
	}

	rep(j,n){
		ull tmp = t[j] ? 0ULL : ans[0][j];
		if(t[j]) rep(i,n) tmp |= ans[i][j];
		else rep(i,n) tmp &= ans[i][j];
		if(v[j] != tmp){
			puts("-1");
			return 0;
		}
	}
	//-------------------------------

	rep(i,n){
		rep(j,n) cout << ans[i][j] << " ";
		cout << endl;
	}
}
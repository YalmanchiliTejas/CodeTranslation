#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
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
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int dp[2020][2020];
int mx2[2020];

int main(){
	int n; cin >> n;
	int N = 3*n;
	vector<int> a(N); rep(i,N) cin >> a[i];
	rep(i,n+1) rep(j,n+1) dp[i][j] = -inf;
	rep(i,n+1) mx2[i] = -inf;
	int mx = -inf;
	rep(i,5){
		rep(j,i){
			int m = -1;
			int ad = 1;
			rep(k,5){
				if(k == i || k == j) continue;
				if(m == -1) m = a[k];
				else{
					if(m != a[k]){
						ad = 0;
						break;
					}
				}
			}
			chmax(dp[a[i]][a[j]], ad);
			chmax(dp[a[j]][a[i]], ad);
			chmax(mx2[a[i]], dp[a[i]][a[j]]);
			chmax(mx2[a[j]], dp[a[j]][a[i]]);
			chmax(mx, dp[a[i]][a[j]]);
		}
	}
	int tmp = 0;
	REP(i,1,n-1){
		int id = i * 3;
		vector<int> v(3);
		rep(j,3) v[j] = a[id+2+j];
		sort(all(v));
		if(v[0] == v[1] && v[1] == v[2]){
			tmp++;
			continue;
		}
		map<pii,int> mp;
		if(v[0] == v[1] || v[1] == v[2]){
			int rest;
			if(v[0] == v[1]) rest = v[2];
			else rest = v[0];
			REP(j,1,n+1){
				if(mp.find({j,rest}) == mp.end()) mp[{j,rest}] = dp[j][v[1]] + 1;
				else chmax(mp[{j,rest}], dp[j][v[1]] + 1);
			}
		}
		rep(j,3){
			vector<int> u;
			rep(k,3){
				if(j == k) continue;
				u.push_back(v[k]);
			}
			if(mp.find({u[0], u[1]}) != mp.end()){
				chmax(mp[{u[0], u[1]}], dp[v[j]][v[j]] + 1);
			}else{
				mp[{u[0], u[1]}] = dp[v[j]][v[j]] + 1;
			}
			chmax(mp[{u[0], u[1]}], mx);
		}
		REP(j,1,n+1){
			rep(k,3){
				if(mp.find({j,v[k]}) == mp.end()) mp[{j,v[k]}] = mx2[j];
				else chmax(mp[{j,v[k]}], mx2[j]);
			}
		}
		for(auto j : mp){
			chmax(dp[j.first.first][j.first.second], j.second);
			chmax(dp[j.first.second][j.first.first], j.second);
			chmax(mx, dp[j.first.first][j.first.second]);
			chmax(mx2[j.first.first], dp[j.first.first][j.first.second]);
			chmax(mx2[j.first.second], dp[j.first.first][j.first.second]);
		}
	}
	int ans = 0;
	rep(i,n+1){
		rep(j,n+1){
			int ad = 0;
			if(i == j && j == a.back()) ad++;
			chmax(ans, dp[i][j] + ad + tmp);
		}
	}
	cout << ans << "\n";
}
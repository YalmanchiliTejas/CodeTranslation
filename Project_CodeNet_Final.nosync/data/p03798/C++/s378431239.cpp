#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 1; i < n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int v[] = {-1,1};

int main(){

 	int n;
 	string st;
 	cin >> n >> st;
 	st += st;
 	V<int> tests(n*2);
 	rep(i,n*2) {
 		if(st[i] == 'o') tests[i] = 1;
 		if(st[i] == 'x') tests[i] = -1;
 	}

 	for(int f : v) for(int s : v) {
 		V<int> ans(n*2+3);
 		ans[0] = f;
 		ans[1] = s;
 		Rep(i,n*2-1) ans[i+1] = ans[i] * ans[i-1] * tests[i];

 		bool ok = true;
 		rep(i,n) {
 			ok &= (ans[i] == ans[i+n]);
 		}
 		if(ok) {
 			rep(i,n) cout << (ans[i] == 1 ? 'S' : 'W');
 			cout << endl;
 			return 0;
 		}
 	}

 	cout << -1 << endl;
 	return 0;
}
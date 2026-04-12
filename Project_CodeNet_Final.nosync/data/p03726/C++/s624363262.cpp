#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

const int MAX_N = 1e5 +10;
vector<int> es[MAX_N];
bool f = true;

bool check(int cur, int par) {
	int cnt = 0;
	if(par != -1 && es[cur].size() == 1) return false;
	for(auto& to : es[cur]) {
		if(to == par) continue;
		if(!check(to, cur)) cnt++;
	}
	if(cnt > 1) f = false;
	return cnt;
} 

int main(){
	int n;
	cin >> n;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		es[a].pb(b);
		es[b].pb(a);
	}
	f &= check(0, -1);
	cout << (f?"Second":"First") << endl;
	return 0;
}
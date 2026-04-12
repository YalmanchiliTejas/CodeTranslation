#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m;i >= n;--i)
#define SORT(v, n) sort(v, v+n)
#define VSORT(v) sort(begin(v), end(v))
#define REV(v) reverse(begin(v), end(v))
#define VI vector<int>
#define PB(x) push_back(x)
#define SZ(x) end(x) - begin(x)
#define DEBUG(x) cerr << __LINE__ << ":" << #x << ": " << x << "\n";
//#define int long long
using namespace std;
using lint = long long;
struct Fast{Fast(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};} fast;
const int INF = INT_MAX;
const lint LINF = LLONG_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
inline void CO(auto &a) {REP(i, SZ(a)) cout << i << ": " << a[i] << "\n";}
//if (IO > 1e5){lint a;	scanf(%lld, &a);	printf("%lld\n", a);}

signed main(){
	int n;
	cin >> n;
	VI h(n);
	REP(i,n) cin >> h[i];
	
	int ans = 1;
	bool f = true;
	FOR(i,1,n){
		REP(j,i){
			if (h[i] < h[j]){
				f = false;
				break;
			}
		}
		if (f) ans++;
		f = true;
	}
	cout << ans << endl;
return 0;
}

#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template<class T, class T2> inline bool chkmax(T &x, const T2 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T2> inline bool chkmin(T &x, const T2 &y) { return x > y ? x = y, 1 : 0; }
const ll mod = 998244353;
template<class T> inline void fix(T &x) {if(x >= mod | x <= -mod) {x %= mod;} if(x < 0) {x += mod;}}
#define out(x) cout << __LINE__ << ": " << (#x) << " = " << (x) << endl
  
const ll MAX_N = 1e6 + 10;
ll prv[MAX_N], when[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, x, m;
    ll beg;
    cin >> n >> x >> m;
    beg = x;
    for(int i = 0; i < MAX_N; i ++) {
    	prv[i] = -1;
    }
    ll sum = x, cnt = 0;
    prv[x] = sum;
    when[x] = ++ cnt;
    ll offset, length, sumoffset, sumcycle;
    while(true) {
    	x = (x * x) % m;
    	if(prv[x] != -1) {
    		offset = when[x] - 1;
    		length = (cnt + 1) - when[x];
    		sumoffset = prv[x] - x;
    		sumcycle = sum + x - prv[x];
    		break;
    	}
    	cnt ++;
    	sum = sum + x;
    	prv[x] = sum;
    	when[x] = cnt;
    }
    ll ans = (n - offset) / length * sumcycle; 
   	n = (n - offset) % length + offset;
   	x = beg;
   	for(int i = 0; i < n; i ++) {
   		ans += x;
   		x = (x * x) % m;
   	}
    cout << ans << endl;
    return 0;
}

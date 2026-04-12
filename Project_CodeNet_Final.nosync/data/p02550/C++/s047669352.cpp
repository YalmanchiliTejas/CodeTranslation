#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))
const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

template <typename T> void print_vec(const vector<T>& v) {
	for(int i = 0; i < SZ(v); i++) {
		if (i) cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

inline ll floorDiv(ll x, ll y) {
	ll d = x / y;
	ll r = x % y;
	return r ? (d - ((x < 0) ^ (y < 0))) : d;
}

ll ceilDiv(ll x, ll y) {
	return -floorDiv(-x,y);
}

bool predicate(ll mid) {
	return mid>10;
}

ll bin_search(ll lo, ll hi) {
	int sign = lo < hi ? 1 : -1;
	lo*=sign;
	hi*=sign;
	hi++;
	while(lo < hi) {
		ll mid = floorDiv(lo+hi,2);
		if (!predicate(sign*mid)) {
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	return sign*lo;
}
const ll MOD = 1000000007;
const int MAXN = 100005;

int seen[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	memset(seen,-1,sizeof seen);
	
	ll n, x, m;
	cin >> n >> x >> m;
	
	ll a = x;
	ll rep = -1;
	seen[x]=1;
	int c = 2;
	while(true){
		a = (a*a)%m;
		if (seen[a] > 0){
			rep = a;
			break;
		}
		seen[a]=c;
		c++;
	}
	c--;
	ll ans = 0;
	
	ll s = 0;
	
	for (ll i = 1; i < m; i++){
		if (seen[i] > 0) {
			if (seen[i]<seen[rep]) {
				ans+=i;
			} else {
				s+=i;
			}
		}
	}
	
	n-=seen[rep]-1;
	c-=seen[rep]-1;
	
	ans+=n/c*s;
	n%=c;
	a = rep;
	for (int i = 0; i < n; i++){
		ans+=a;
		a = (a*a)%m;
	}
	cout << ans << "\n";
	
}

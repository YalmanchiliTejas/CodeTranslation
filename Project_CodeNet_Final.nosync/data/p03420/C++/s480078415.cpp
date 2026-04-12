#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<deque>
#include<functional>
#include<ctime>
#include<cassert>
#include<cstring>
#include<unordered_map>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<=b;++i)
#define fj(a,b) for(int j=a;j<=b;++j)
#define fo(a,b) for(int o=a;o<=b;++o)
#define fdi(a,b) for(int i=a;i>=b;--i)
#define fdj(a,b) for(int j=a;j>=b;--j)
#define fdo(a,b) for(int o=a;o>=b;--o)
#define pb push_back
#define mp make_pair
#ifdef LOCAL
#define err(format, ...) fprintf(stderr, format, __VA_ARGS__);
#else
#define err(format, ...) while(false) {}
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef vector<int> vi;

template<class T> bool uin(T &a, T b){ return (a > b ? a = b, true : false); }
template<class T> bool uax(T &a, T b){ return (a < b ? a = b, true : false); }

/////////////////////////////////

int n, k;
ll ans;

int calc(int a) {
	int cur = a;
	int res = 0;
	while(cur <= n) {
		int q;
		int x = cur + 1;
		int y = cur + a - 1;
		y = min(y, n);
		q = max(0, y - x + 1 - k + 1);
//		err("a = %d x = %d y = %d q = %d\n", a, x, y, q);
		res += q;
		cur += a;
	}
//	err("a = %d res = %d\n", a, res);
	return res;
}

void solve() {
	fi(1, n) {//a < b
		if (k != 0) {
			ans += max(0, i - k);
		} else {
			ans += max(0, i - 1);
		}
	}	     	
	fi(1, n) {
		ans += calc(i);
	}			
}

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d", &n, &k);	
	solve();		
	printf("%lld\n", ans);

	
#ifdef LOCAL
	fprintf(stderr, "ELAPSED TIME: %.3lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}
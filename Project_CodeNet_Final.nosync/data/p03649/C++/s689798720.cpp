#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

ll a[100];

void next(int n, ll a[]){
	a[0] -= n;
	for (int i = 1; i < n; ++i)
		++a[i];
	int k = 0;
	for (; k < n && a[k] < a[k + 1]; ++k)
		swap(a[k], a[k + 1]);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	sort(a, a + n, greater<ll>());

	ll ans = 0;
	for (int i = 1; i < n; ++i){
		if (a[i - 1] - a[i] >= n + 1){ // - n + (i - 1), +(i), dis: n + 1
			ll d = (a[i - 1] - a[i]) / (n + 1);
			for (int j = 0; j < i; ++j)
				a[j] += d * (-n + (i - 1));
			for (int j = i; j < n; ++j)
				a[j] += d * i;

			ans += d * i;
			sort(a, a + n, greater<ll>());

			eput(i, d, ans, vector<int>(a, a + n));
		}
		while (a[0] >= a[i] + n)
			next(n, a), ++ans;
	}
	if (a[n - 1] >= n){
		ll d = a[n - 1] - n;
		ans += d * n;
		for (int i = 0; i < n; ++i)
			a[i] -= d;
	}
	while (a[0] >= n)
		next(n, a), ++ans;
	printf("%lld\n", ans);
	return 0;
}

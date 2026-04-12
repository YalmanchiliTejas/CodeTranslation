#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
#ifdef VC
#define scanf scanf_s
#endif
#define iINF (1<<30)
#define INF (1LL<<59)
#define forn(i) for(int i = 0;i < n; ++i)
#define form(i,n) for(int i = 0 ;i < n; ++i)
#define NIL -1

const int mod = 1000000007;

int n, m;


int main(){
	ll a[200010], b[200010];
	cin >> n;
	forn(i) {
		scanf("%lld", &a[i]); 
		b[i] = a[i];
	}
	sort(a, a + n);
	forn(i) {
		if (b[i] <= a[n / 2 - 1]) {
			printf("%lld\n", a[n / 2]);
		}
		else {
			printf("%lld\n", a[n / 2-1]);
		}
	}
	return 0;
}
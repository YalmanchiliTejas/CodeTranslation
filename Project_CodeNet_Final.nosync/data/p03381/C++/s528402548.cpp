#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;

/////////////////////////////////

int const MAX = 2e5 + 41;

int pos[MAX];
int n;
int a[MAX];
int ans[MAX];
pii b[MAX];

void solve() {
	fi(1, n) {
		b[i] = mp(a[i], i);
	}
	sort(b + 1, b + n + 1);
	fi(1, n) {
		pos[b[i].second] = i;
	}
	fi(1, n) {
		int p = pos[i];
		err("i = %d p = %d\n", i, p);
		if (p <= n / 2) {
			ans[i] = b[n / 2 + 1].first;
		} else {
			ans[i] = b[n / 2].first;
		}
	}
	fi(1, n) {
		printf("%d\n", ans[i]);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}
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
typedef vector<ll> vll;
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;

/////////////////////////////////

int const MAX = 2e5 + 41;

char s1[MAX];
char s2[MAX];

string a, b;

int n;

void solve() {
	a = string(s1 + 1);
	b = string(s2 + 1);
	if (a + b > b + a) {
		swap(a, b);
	}
	fi(0, n) {
		int len = i * sz(b);
		if ( (n - len) % sz(a) == 0) {
			int q = (n - len) / sz(a);
			fj(1, q) {
				printf("%s", a.c_str());
			}
			fj(1, i) {
				printf("%s", b.c_str());
			}			
			return;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  scanf(" %s", s1 + 1);
  scanf(" %s", s2 + 1);
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}
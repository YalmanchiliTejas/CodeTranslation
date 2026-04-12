#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int mod = 1000*1000*1000+7;

int n;
int m;
int res[110][110];
int h[110];
vi w;

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	scanf ("%d", &n);
	h[0] = 1;
	w.pb (1);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &h[i]);
		w.pb (h[i]);
	}
	sort (all (w));
	w.resize (unique (all (w)) - w.begin ());
	res[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz (w); j++) {
			if (j == 0) {
				res[i + 1][0] = (res[i + 1][0] + (ll)res[i][j] * 2) % mod;
				for (int k = 1; k < sz (w); k++) {
					int a = max (h[i], w[k - 1]);
					int b = min (h[i + 1], w[k]);
//					printf ("%d %d\n", a, b);
					if (a <= b) {
						ll tmp = power (2, h[i + 1] - a) - power (2, h[i + 1] - b);
						if (tmp < 0) tmp += mod;
						res[i + 1][k] = (res[i + 1][k] + (ll)res[i][j] * 2 * tmp) % mod;
					}
				}	
			} else {
				if (w[j] <= h[i + 1]) {
					res[i + 1][j] = (res[i + 1][j] + (ll)res[i][j] * power (2, max (0, h[i + 1] - h[i]))) % mod;
				} else {
					res[i + 1][0] = (res[i + 1][0] + (ll)res[i][j] * 2) % mod;
				}
			}
//			printf ("%d,%d : %d = %d\n", i, h[i], w[j], res[i][j]);
		}
	int ans = 0;
	for (int i = 0; i < sz (w); i++) {
//		printf ("%d = %d\n", i, res[n][i]);
		ans = (ans + res[n][i]) % mod;
	}	
	printf ("%d\n", ans);
	return 0;
}
//This is getting accepted!
// I HATE BUG
// God Of The Bugs
#include<bits/stdc++.h>

using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll
#define ld long double

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
template<class T> T sqr(T x) { return x * x; }

inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

int H, W, vs[30][30];
string s[30];

void go(int i, int j) {
	if (i >= H || j >= W) return;
//	cout << i << " " << j << endl;
	vs[i][j] = 1;
	if (j < W - 1 && s[i][j + 1] == '#') go(i, j + 1);
	else if (i < H - 1 && s[i + 1][j] == '#') go(i + 1, j);
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//#endif

	cin >> H >> W;
	for (int i=0; i<H; i++) {
		cin >> s[i];
	}
	
	int ok = 0;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if (s[i][j] == '#' && !vs[i][j]) {
				if (!ok) go(i, j), ok = 1;
				else {
					cout << "Impossible";
					return 0;
				}
			} 
		}
	}
	
	cout << "Possible";


}

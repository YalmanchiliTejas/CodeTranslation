//This is getting accepted!
// I HATE BUG
// God Of The Bugs
// 12/11/2016
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
const int MAXN = 2e5 + 5;
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

deque<int> st;
int n, a[MAXN];

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);
//#endif

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=0; i<n; i++) {
		if (i % 2) st.push_back(a[i]);
		else st.push_front(a[i]);
	}
	
	while (!st.empty()) {
		if (n % 2 == 0) {
			cout << st.back() << " ";
			st.pop_back();
		}
		else {
			cout << st.front() << " ";
			st.pop_front();
		}
	}

	return 0;
}

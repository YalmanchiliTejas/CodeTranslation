#include <bits/stdc++.h>
using namespace std;

#define FORE(i, a) for (auto i = a.begin(); i != a.end(); ++i)
#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

vector<string> split(const string &s, char c) {
	vector<string> v; stringstream ss(s); string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}
#define DEBUG(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << "[DEBUG] " << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> a(n), b(n);
	REPU(i, 0, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(ALL(b));
	int pos = n / 2;
	REPU(i, 0, n) {
		int idx = lower_bound(ALL(b), a[i]) - b.begin() + 1;
		if (idx > pos) printf("%d\n", b[pos - 1]);
		else printf("%d\n", b[pos]);
	}

	return 0;
}

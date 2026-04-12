#include <bits/stdc++.h>
#define ADD(a, b) a = (a + (ll)b) % mod
#define MUL(a, b) a = (a * (ll)b) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rer(i, a, b) for(int i = a - 1; i >= b; i--)
#define all(a) (a).begin(), (a).end()
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;
typedef vector<ll> vec;

const int MAX_N = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const ll inf = 1LL << 60;

void Debug() {cout << '\n'; }

template<class FIRST, class... REST> 
void Debug(FIRST arg, REST... rest) { cout << arg << " "; Debug(rest...); }

template<class T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	if(!v.empty()) {
		rep(i, 0, (int)v.size() - 1) out << v[i] << ", ";
		out << v.back();
	}
	out << "]";
  return out;
}

template<class S, class T>
ostream& operator<< (ostream& out, const pair<S, T>& v) {
	out << "(" << v.first << ", " << v.second << ")";
	return out;
}

///g++ -g3 -std=c++0x -DLOCAL -Wall -ftrapv -D_GLIBCXX_DEBUG -Wl,-stack,268435456 -o
///g++ -O2 -std=c++0x -DLOCAL -Wall -Wl,-stack,268435456 -o

///////////////////////////////////////////////////////////////////////

int N;

void solve() {
	cin >> N;
	deque<int> que;
	rep(i, 0, N) {
		int a; cin >> a;
		if(i % 2 == 0) que.push_front(a);
		else que.push_back(a);
	}
	if(N % 2 == 0) {
		rep(i, 0, N) {
			cout << que.back() << " ";
			que.pop_back();
		}
		cout << "\n";
	}
	else {
		rep(i, 0, N) {
			cout << que.front() << " ";
			que.pop_front();
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);	
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}



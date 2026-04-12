#include <bits/stdc++.h>

using namespace std;

#define PB	push_back
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP	make_pair

#define debug(args...) { string _s = #args; replace(ALL(_s), ',', ' '); stringstream ss(_s); cerr << endl;_debug(ss, args); }
#define _rg auto it = next(v.begin()); it != v.end(); it++
#define _input ostream& operator <<(ostream& out

template<typename T, typename U>
_input, const pair<T, U>& p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

#define cont(c) template<typename T> _input, const c<T>& v) { \
					if (v.empty()) return out; \
					out << "[" << *v.begin(); \
					for (_rg) out << ", " << *it; \
					out << "]"; return out; \
				}
				
#define cont2(c) template<typename T, typename U> _input, const c<T, U>& v) { \
					if (v.empty()) return out; \
					out << "[" << *v.begin(); \
					for (_rg) out << ", " << *it; \
					out << "]"; return out; \
				}

cont(vector) cont(set) cont(multiset) cont(queue) cont2(map)

template<typename T, size_t n, typename= enable_if_t<!is_same<T, char>::value>>
_input, const T(&v)[n]) {
	if (n == 0) return out;
	out << "[" << v[0];
	for (int i = 1; i < (int)n; i++) out << ", " << v[i];
	out  << "]"; return out;
}

template<typename T, typename... Ts>
void _debug(stringstream& ss, const T &arg) {
	string name; ss >> name;
	cerr << name << " = " << arg << endl;
}

template<typename T, typename... Ts>
void _debug(stringstream& ss, const T& arg, const Ts&... args) {
	string name; ss >> name; 
	cerr << name << " = " << arg << ", ";
	if (is_class<T>::value || is_array<T>::value) cerr << endl;
	_debug(ss, args...);
}

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)

#define int long long int

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;

const int INF = LONG_LONG_MAX>>1;
const int NINF = LONG_LONG_MIN/2;
const double PI = 3.141592653589793238;

const int N = 200009;
vii ivl[N];

// add to the prefix
// giv the min of everything

struct S {
	int small, lazy;
	void merge(const S& a, const S& b) {
		small = min(a.small, b.small);
	}
	void add(int x) {
		small += x;
		lazy += x;
	}
};

vector<S> tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, int& x) {
	if (high < q_low || q_high < low) {
		return ;
	}
	
	if (q_low <= low && high <= q_high) {
		if (type == TYPE_ADD) {
			tree[id].add(x);
		} else if (type == TYPE_MIN) {
			x = min(x, tree[id].small);
		} else {
			assert(false);
		}
		return;
	}
	for (int b: {2*id, 2*id + 1}) {
		tree[b].add(tree[id].lazy);
	}
	tree[id].lazy = 0;
	int last_left = (low+high) / 2;
	rec(2*id, low, last_left, q_low, q_high, type, x);
	rec(2*id + 1, last_left+1, high, q_low, q_high, type, x);
	
	tree[id].merge(tree[2*id], tree[2*id+1]);
}


int32_t main() {
	FAST_IO;
	
	int n, m;
	cin >> n >> m;
	int sum_of_scores = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ivl[b].emplace_back(a, c);
		sum_of_scores += c;
	}
	int answer = 0;
	int base = 1;
	while(base <= n+1) {
		base *= 2;
	}
	tree.resize(2*base, {INF, 0});
	
	int whatever = -INF;
	rec(1, 0, base - 1, 0, 0, TYPE_ADD, whatever);
	
	for (int i = 1; i <= n+1; i++) {
		// I want to put '1' here
		for (ii p: ivl[i-1]) {
			rec(1, 0, base - 1, 0, p.first-1, TYPE_ADD, p.second);
		}
		int best = INF;
		rec(1, 0, base-1, 0, base-1, TYPE_MIN, best);
		if (i == n+1) {
			answer = best;
		}
		whatever = best - INF;
		rec(1, 0, base - 1, i, i, TYPE_ADD, whatever);
	}
	
	cout << sum_of_scores - answer << endl;
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined -std=c++17

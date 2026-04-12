#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second

typedef long long ll;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

double get_time() {
	return 1.0 * clock() / CLOCKS_PER_SEC;
}

int32_t main() {
	long long n;
	int x, m;
	cin >> n >> x >> m;

	long long res = 0;
	vector<int> seen(m);

	// int prev = x;
	// for(int i = 0; i )
	int ele = 0, st = 0, p = 0;

	for(int i = 0, cur = x; ; i++) {
		// debug(cur);
		if(seen[cur]) {
			p = i + 1 - seen[cur];
			st = seen[cur];
			ele = cur;
			debug(1, cur, p, st, ele);
			break;
		}
		seen[cur] = i + 1;
		cur = (long long) cur * cur % m;
		// deg(cur);
		// debug(cur);
	}

	debug(p, st, ele);

	for(int i = 0, cur = x; i < st - 1 && n > 0; i++, n--) {
		res += cur;
		cur = (long long) cur * cur % m;
	}

	long long sum = 0;

	
	
	for(int i = 0, cur = ele; i < p; i++) {
		sum += cur;
		cur = (long long) cur * cur % m;
	}


	debug(n, sum, p);
	res += (long long) sum * (n / p);

	n %= p;

	for(int i = 0, cur = ele; i < n; i++) {
		res += cur;
		cur = (long long) cur * cur % m;
	}

	cout << res << '\n';

}

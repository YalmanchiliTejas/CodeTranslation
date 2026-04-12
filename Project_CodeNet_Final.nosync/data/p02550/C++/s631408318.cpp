#define LOCAL

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f


#define LOCAL

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

using llong = long long;
using PII = pair<int, int>;

const llong MOD = 998244353LL;
const double PI = acos(-1);

int main() {
	IOS;
	llong n, x, m; cin >> n >> x >> m;
	vector<llong> pos(m, -1);
	pos[x] = 0;
	llong cur = x;
	vector<llong> seq;
	int cnt = 0;
	seq.push_back(x);
	int s, e;
	while (1) {
		cur *= cur;
		cur %= m;
		if (pos[cur] != -1) {
			s = pos[cur];
			e = cnt;
			break;
		}
		cnt++;
		pos[cur] = cnt;
		seq.push_back(cur);
	}
	vector<llong> init, cycle;
	for (int i = 0; i < s; i++) init.push_back(seq[i]);
	for (int i = s; i <= e; i++) cycle.push_back(seq[i]);
	if (n <= (int)init.size()) {
		llong sum = 0;
		for (int i = 0; i < n; i++) sum += init[i];
		cout << sum;
		return 0;
	}
	else {
		llong sum = 0;
		for (int i = 0; i < init.size(); i++) sum += init[i];
		n -= init.size();
		llong cyclesum = 0;
		for (int i = 0; i < cycle.size(); i++) cyclesum += cycle[i];
		sum += (n / cycle.size()) * cyclesum;
		n %= (int)cycle.size();
		for (int i = 0; i < n; i++) sum += cycle[i];
		cout << sum;
	}
}
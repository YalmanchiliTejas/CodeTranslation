#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ini(a, i) memset(a, i, sizeof(a))
#define inin(a, n, i) memset(a, i, sizeof(a[0])*(n))
#define contains(c, i) ((c).find(i) != (c).end())
#define present(i, c) (find(all(c), i) != (c).end())

#define trav(x, c) for(auto &x : c)
#define rep(i, n) for(int i = 0; i < n; i++)
#define repa(i, b, e) for(int i = (b)-((b)>(e)); i != (e)-((b)>(e)); i += 1-2*((b)>(e)))
	
template<class T> bool chkmax(T &x, T y) { return x < y ? x = y, true : false; }
template<class T> bool chkmin(T &x, T y) { return x > y ? x = y, true : false; }
template<class A, class B> A cvt(B x) { stringstream s; s << x; A r; s >> r; return r; }

void read() {}
void print() {}
template<class T, class... Args> void read(T& a, Args&... args) { cin >> a; read(args...); }
template<class T, class... Args> void print(T a, Args... args) { cout << a << ' '; print(args...); }
template<class... Args> void println(Args... args) { print(args...); cout << endl; }

#define debug(args...) { string s_(#args); replace(all(s_), ',', ' '); stringstream ss_(s_); istream_iterator<string> it_(ss_); cerr_(it_, args); }
void cerr_(istream_iterator<string> it) { (void) it; }
template<class T, class... Args> void cerr_(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; cerr_(++it, args...); }

template<class T, class S>  ostream& operator<<(ostream& os, const pair<T, S>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<class T> ostream& operator<<(ostream &os, const set<T> &s) { os << '{'; string sep; for (const auto &x : s) os << sep << x, sep = ", "; return os << '}'; }
template<class T, class S> ostream& operator<<(ostream &os, const map<T, S> &m) { os << '{'; string sep; for (const auto &x : m) os << sep << x, sep = ", "; return os << '}'; }
template<class T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }

//=========================

void run_test() {
	int x; read(x);
	println((x >= 30 ? "Yes" : "No"));
}

//=========================

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//int t_ = 1, t__; cin >> t__; while(t_ <= t__) { cout << "Case #" << t_++ << ": "; run_test(); }
	// int t_; cin >> t_; while(t_--) run_test();
	run_test();
	return 0;	
}

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define Abs(x)((x) < 0 ? (x) * -1 : (x))
 
#define rep(x, y) for ((x) = 0; (x) < (y); (x)++)
#define repin(x, y) for ((x) = 0; (x) <= (y); (x)++)
#define nep(x, y) for ((x) = (y) - 1; 0 <= (x); (x)--)
#define nepi(x, y, z) for ((x) = (y) - 1; (z) <= (x); (x)--)
#define repi(x, y, z) for ((x) = (z); (x) < (y); (x)++)
#define repiin(x, y, z) for ((x) = (z); (x) <= (y); (x)++)
#define reps(x, y, z) for ((x) = 0; (x) < (y); (x) += (z))
#define repis(x, y, z, s) for ((x) = (z); (x) < (y); (x) += (s))
#define repiins(x, y, z, s) for ((x) = (z); (x) <= (y); (x) += (s))
#define repit(x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define repit2(x) for (__typeof((x).begin()) it2 = (x).begin(); it2 != (x).end(); it2++)
#define nepit(x) for (__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)
 
#define All(x) (x).begin(),(x).end()
 
#define Mem0(x) memset(x, 0, sizeof(x))
#define Mem1(x) memset(x, -1, sizeof(x))
 
// can be applied to string type
#define Unique(v) v.resize(unique(All(v)) - v.begin())
 
#define peq(p0, p1)(p0.first == p1.first && p0.second == p1.second)
 
#define End '\n'
#define Out(x) cout<<(x)<<End
#define YES cout<<"YES"<<End
#define NO cout<<"NO"<<End
#define Yes cout<<"Yes"<<End
#define No cout<<"No"<<End
template<typename T>
void Outln(const string &sep, const T &val) { cout << val << End; }
template<typename T, typename... Args>
void Outln(const string &sep, const T &val, Args... args) {
    cout << val << sep;
	Outln(sep, std::forward<Args>(args)...);
}
template<typename T>
void OutN(T x) {
	size_t i, len = x.size() - 1;
 
	for (i = 0; i < len; i++) cout << x[i] << " ";
	cout << x[len] << '\n';
}
#define OutaN(x)                                                     \
    do {                                                             \
        size_t i, len = sizeof(x) / sizeof(__typeof(x[0])) - 1;      \
        for (i = 0; i < len; i++) cout << x[i] << " ";               \
        cout << x[len] << '\n';                                      \
    } while (0);
 
template<typename T>
void Outit(T x) {
	auto end = x.end();
 
	end--;
	
	for (auto it = x.begin(); it != end; it++) cout << *it << " ";
	cout << *end << '\n';
}
template<typename T>
void Debug(const T &val) { cerr << val << End; }
template<typename T, typename... Args>
void Debug(const T &val, Args... args) {
    cerr << val << ' ';
	Debug(std::forward<Args>(args)...);
}
 
template<typename T> inline bool Max(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template<typename T> inline bool Min(T &x, const T &y) { return x > y ? x = y, 1 : 0; }
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T> >;
 
// can be applied to string type
#define Sort(v) sort(All(v))
#define SortR(v) sort(All(v), std::greater<__typeof(v[0])>())
// array sorters
#define Sart(a) sort(a, a + sizeof(a) / sizeof(__typeof(a[0])));
#define SartR(a) sort(a, a + sizeof(a) / sizeof(__typeof(a[0])), std::greater<__typeof(a[0])>())
 
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define lb std::lower_bound
#define ub std::upper_bound
 
#define lbi(v, x) lb(All(v), (x))-v.begin()
#define ubi(v, x) ub(All(v), (x))-v.begin()
 
inline bool isSame(const string &a, const string &b) { return a.compare(b) == 0; }
inline bool isLess(const string &a, const string &b) { return a.compare(b) < 0; }
inline bool isGreater(const string &a, const string &b) { return a.compare(b) > 0; }
inline string Str(const char &ch, const int &n) { return string(n, ch); }
inline string Str(const int &n, const char &ch) { return string(n, ch); }
vector<string> getStrLine() {
	vector<string> v;
	string str;
 
	getline(cin, str);
 
	istringstream iss(str);
 
	for (string word; iss >> word;) v.push_back(word);
 
	return v;
}
 
static const ll MOD = 1e9 + 7;
static const double PI = 3.141592653589793;

/*** ATCODER, CODECHEF and TOPCODER ***/

// -2147483648 <= INT <= 2147483647
// -9223372036854775808 <= LONG <= 9223372036854775807
// -9223372036854775808 <= LLONG <= 9223372036854775807

/*** END ***/

/*** CODEFORCES ***/

// -2147483648 <= INT <= 2147483647
// -2147483648 <= LONG <= 2147483647
// -9223372036854775808 <= LLONG <= 9223372036854775807

/*** END ***/

struct Node {
	int id;
	V<int> connects;
};

void rec(const V<Node> nodes, const int &n, const int &index, const int &num, map<int, bool> table, int &ans) {
	if (table[index]) return;
	if (n <= num) {
		ans++;

		return;
	}

	table[index] = 1;
    
	int i, len = nodes[index].connects.size();

	rep(i, len) rec(nodes, n, nodes[index].connects[i], num + 1, table, ans);
}

void solve(const V<Node> nodes, const int &n) {
	int ans = 0;
	map<int, bool> table;
	
    rec(nodes, n, 0, 1, table, ans);

	Out(ans);
}

#define LOCAL 0
 
int main()
{
#if LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
 
    cin.tie(0);
    ios::sync_with_stdio(false);
	//std::cout.precision(18);

    int n, m;

	cin >> n >> m;

	V<Node> nodes(n);
	int a, b;

	int i;

	rep(i, m) {
		cin >> a >> b;

		a--;
		b--;

		nodes[a].connects.pb(b);
		nodes[b].connects.pb(a);
	}

    solve(nodes, n);
	
	return 0;
}

// Bismillahir Rahmanir Rahim
// S. M. Shakir Ahsan Romeo
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int dx4[] = { -1, 0, 1, 0 }; // 4 direction i
const int dy4[] = { 0, 1, 0, -1 }; // 4 direction j
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 8 direction i
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 8 direction j
const int dxk[] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // knight direction i
const int dyk[] = { -1, 1, -2, 2, -2, 2, -1, 1 }; // knight direction j
typedef long long lng;
typedef unsigned long long ulng;
typedef double db;
typedef vector < int >  vi;
typedef pair < int, int >  pii;
typedef pair < long long, long long >  pll;
typedef vector < pair < int, int > >  vpii;
typedef vector < pair < long long, long long > >  vpll;
#ifdef __linux__
#define GC getchar_unlocked
#else
#define GC getchar
#endif
inline long long Int()
{
	long long inputNumber = 0; char c = GC(); bool sign = true;
	while (!((c >= '0' && c <= '9') || c == '-')) c = GC();
	if (c == '-') sign = false, c = GC();
	while (c >= '0' && c <= '9') inputNumber = (inputNumber << 1) + (inputNumber << 3) + c - '0', c = GC();
	return sign ? inputNumber : -inputNumber;
}
#define II Int()
template < class S, class T > ostream& operator << (ostream& out, const pair < S, T >& Pair)
{
	out << '{' << Pair.first << ", " << Pair.second << '}';
	return out;
}

template < class T > ostream& operator << (ostream& out, const vector < T >& Vector)
{
	out << '[';
	for (int i = 0; i < (int)Vector.size(); ++i)
	{
		out << Vector[i];
		if (i + 1 < (int)Vector.size())
			out << ", ";
	}
	out << ']';
	return out;
}

template < class S, class T> ostream& operator << (ostream& out, const map < S, T >& Map)
{
	out << "[\n";
	for (const auto& x : Map)
	{
		out << "{ Key: " << x.first << " , Value: " << x.second << " }\n";
	}
	out << "]\n";
	return out;
}

template < class T > ostream& operator << (ostream& out, const multiset < T >& Set)
{
	out << '{';
	for (auto it = Set.begin(); it != Set.end();)
	{
		out << *it;
		it++;
		if (it != Set.end())
			out << ", ";
	}
	out << '}';
	return out;
}

void solve();
#define PureProtea main()
#define xx first
#define yy second
#define endl '\n'
#define sf scanf
#define pf printf
#define PC putchar
#define NL putchar('\n')
#define SP putchar(' ')
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define _find(x, y) ((x).find((y)) != (x).end())
#define sqr(x) ((x) * (x))
#define mem(x, y) memset((x), (y), sizeof((x)))
#define wait system("pause");
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end());
#define Time cerr << "\nElapsed time: " << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
#define forcon(x, y) for(const auto& x : (y))
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define repb(i, n) for(int i = (n) - 1; i >= 0; --i)
#define repb1(i, n) for(int i = (n); i >= 1; --i)
#define repab(i, a, b) for(int i = (a); i <= (b); ++i)
#define repba(i, a, b) for(int i = (a); i >= (b); --i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define repstl(x, y) for(auto x = (y).begin(); x != (y).end(); x++)
#define repbstl(x, y) for(auto x = (y).rbegin(); x != (y).rend(); x++)
#define segtree int lft = node << 1, rgt = lft | 1, mid = (b + e) >> 1;
#define Case int __T; scanf("%d", &__T); for(int cas = 1; cas <= __T; ++cas)
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

int PureProtea
{
	//FAST;
	//cout << fixed << setprecision(15);
	//cerr << fixed << setprecision(15);
	solve();
#ifdef ROMEO
Time;
#endif // ROMEO
}

const double eps = 1e-10;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;


void solve()
{
	int n = II, ans = 1; vi v(n); rep(i, n) v[i] = II;
	int mx = v.front(); for (int i = 1; i < n; ++i) {
		if (v[i] >= mx) {
			++ans;
			mx = max(mx, v[i]);
		}
	}cout << ans;
}
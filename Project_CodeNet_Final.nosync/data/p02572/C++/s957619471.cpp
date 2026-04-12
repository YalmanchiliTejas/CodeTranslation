#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define int long long
#define mod 1000000007
#define DEBUG cout<<"Hello1\n";
#define all(v) (v).begin(),(v).end()
#define clr(x) memset(x,0,sizeof(x))
#define deb(...) debug(#__VA_ARGS__, __VA_ARGS__);
const int N = 1e6 + 5;
const double pi =  acosl(-1);
const long long inf = 1e18 + 5;
using namespace std;
template<typename T> void debug(string s, T x)
{
	cout << s << " = " << x << "\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args)
{
	cout << s.substr(0, s.find(',')) << " = " << x << " | ";
	debug(s.substr(s.find(',') + 2), args...);
}
template<class T> void print_container(T &container)
{
	for (auto &t : container)
	{
		cout << t << " ";
	}
	cout << endl;
}
template<class T> void print_pair_container(T &container)
{
	for (auto &t : container)
	{
		cout << t.first << " " << t.second << endl;
	}
	cout << endl;
}
template<class T> void printArr(T &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
typedef long long ll;
typedef pair<int, int> pii;

//Template Ends
int n;
int a[N];

ll power(ll a, ll n, ll m) {
	a %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2)
			res = res * a % m;
		a = a * a % m;
		n /= 2;
	}
	return res;
}



void solve()
{
	ll e = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		e += a[i];
		e %= mod;
	}

	e = power(e, 2, mod);


	ll prod = 0;
	for (int i = 0; i < n; i++) {
		prod += power(a[i], 2, mod);
		prod %= mod;
	}

	ll ans = (e - prod + mod) % mod;

	ans = (ans * power(2, mod - 2, mod)) % mod;

	cout << ans << endl;
}

int32_t main()
{
	IOS;

	solve();

	return 0;
}



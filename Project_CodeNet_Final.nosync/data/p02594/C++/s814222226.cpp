#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i,n)       for(int i=0; i<n; i++)
#define clr(arr)       memset(arr, 0, sizeof arr)
#define all(x)         x.begin(), x.end()
const int MOD = 1e9 + 7;

#ifdef SMIT
template<class F, class S> ostream& operator<<(ostream &out, const pair<F, S> &p)
{
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out)
{
	out << '{';
	for (auto i = x.begin(); i != x.end(); i++)
		out << *i << (i == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dmp() {}
template<class T, class... Args> void dmp(T &&x, Args... args)
{
	cerr << x << ";  "; dmp(args...);
}
struct Nl {~Nl() {cerr << '\n';}};
#define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dmp(x), Nl(), cerr << ""
#else
#define debug(...) {}
#endif
// Yes you CAN


int n;
void solve()
{
// #define TEST
	cin >> n;
	if (n >= 30)  cout << "Yes" << endl;
	else cout << "No" << endl;
}

int32_t main()
{
#ifdef SMIT
	// freopen("/home/smit/Desktop/in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
#ifdef TEST
	cin >> t;
#endif
	while (t--)
		solve();
}
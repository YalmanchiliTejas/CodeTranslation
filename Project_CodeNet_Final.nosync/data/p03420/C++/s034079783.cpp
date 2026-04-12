#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007LL
#define eps 1e-13
#define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define mp make_pair
#define F first
#define S second
#define pb(x) push_back(x)
#define fo(i,a,n) for(i = (a); i < (n); i++)
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define sws ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin); freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

ll modx(ll Base, ll exponent)
{
	ll ans = 1;
	if(Base == 1)
		return Base;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}

ll inmodx(ll num)
{
	return (modx(num, mod-2LL));
}

bool cmp(pair < pll, int > a, pair < pll, int > b)//true for a before b
{
	ll val = a.F.F*b.F.S - a.F.S*b.F.F;
	if(val >= 0LL)
		return 1;
	return 0;
}

const int N = (1e5) + 9;
const int M = (N<<2) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;
const int BUCK = 8000;



void solve()
{
	ll n, k, b, r, ans = 0LL;
	cin >> n >> k;
	fo(b,k+1LL,n+1LL)
	{
		ans += ((n/b)*(b-k));
		ans += max((n%b)-k+1LL,0LL);
		if(k == 0LL)
			ans--;
	}
	cout << ans;
	return;
}

int main()
{
	sws;
	// clock_t clk;
	// clk = clock();
	// io_file;
	// srand (time(NULL));

	//Code here
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	// Code ends here

	// clk = clock() - clk;
	// cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}
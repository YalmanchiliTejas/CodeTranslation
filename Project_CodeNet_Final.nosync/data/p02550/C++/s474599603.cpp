#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#include <ctime>
#include<bitset>

//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e9;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(ll i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using Graph = vector<vector<ll>>;

#define ketasitei setprecision(15) //15桁表示

const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = 3.1415926535897932;



int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << ketasitei;
	
	ll n, x, m;
	cin >> n >> x >> m;

	vector<ll> used(m + 1, 0);
	used[x]++;
	ll sum = 1;
	ll ans = 0;
	ll i=x;

	if (n <= 10000000)
	{
		for (int i = 0; i < n; i++)
		{
			ans += x;
			x = (x * x) % m;
		}
		cout << ans << endl;
		ret;
	}

	do
	{
		ans += i;
		used[i] = sum;
		i = (i * i) % m;
		sum++;
	} while (!used[i]);

	if (i == 0)
	{
		cout << ans << endl;
		ret;
	}

	ll res = 0;
	ll xx = i;
	ll j;
	for ( j = 0; j < sum - used[i]; j++)
	{
		res += xx;
		xx = (xx * xx) % m;
	}
	ans += ((n - (sum - 1)) / (sum - used[i])) * res;
	n -= sum - 1;
	n %= (sum - used[i]);

	for (int i = 0; i < n; i++)
	{
		ans += xx;
		xx = (xx * xx) % m;
	}

	cout << ans << endl;

	return 0;
}
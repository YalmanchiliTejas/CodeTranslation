#pragma optimize GCC("Ofast")
#pragma comment(linker, "/STACK:1073741824")

#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<fstream>
#include<iterator>
#include<functional>
#include<bitset>
#include<memory>
#include<sstream>
#include<new>
#include<cassert>
#include<iomanip>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<bool, bool> pbb;
typedef pair<ld, ld> pdd;

const int inf = (int)1e9 + 9;
const ll linf = (ll) 1e18;
const ld eps = 1e-7;
const int mod = (int) 1e9 + 7;

#define it(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define scn second
#define sgn(x) (x > 0 ? 1 : (x == 0 ? 0 : -1))

signed main()
{
	ios_base::sync_with_stdio(false);
	srand(time(0));
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	ll res = 0;
	for (int b = k + 1; b < n + 1; b++)
	{
		int mul = 0;
		while (mul * b + k <= n)
		{
			res += min(n, (mul + 1) * b - 1) - mul * b - k + 1;
			if (mul * b + k == 0)
			{
				res--;
			}
			mul++;
		}
	}
	cout << res;
}
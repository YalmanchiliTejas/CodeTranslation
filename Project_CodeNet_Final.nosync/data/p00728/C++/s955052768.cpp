#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, n) for (int i = (n)-1; i >= 0; i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase(unique(ALL(v)), v.end());

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 2e18;
const double PI = acos(-1);

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N != 0)
	{

		int mav = 0;
		int miv = 1000;
		int sum = 0;
		REP(i, N)
		{
			int a;
			cin >> a;
			sum += a;
			mav = max(mav, a);
			miv = min(miv, a);
		}
		cout << (sum - mav - miv) / (N - 2) << endl;
		cin >> N;
	}
	return 0;
}


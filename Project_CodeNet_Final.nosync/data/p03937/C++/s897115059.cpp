#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string m[10];
int H, W;

bool check(int h, int w, vector<string> s)
{
	if (h >= H || w >= W)
	{
		return false;
	}
	if (m[h][w] == '.')
	{
		return false;
	}
	s[h][w] = '.';
	if (h == H - 1 && w == W - 1)
	{
		REP(i, H)
		{
			REP(j, W)
			{
				if (s[i][j] == '#')
				{
					return false;
				}
			}
		}
		return true;
	}

	return check(h + 1, w, s) || check(h, w + 1, s);
}

int main()
{
	cin >> H >> W;
	REP(i, H)
	{
		cin >> m[i];
	}

	vector<string> t(H);
	REP(i, H)
	{
		t[i] = m[i];
	}

	string s = "Impossible";
	if (check(0, 0, t))
	{
		s = "Possible";
	}
	cout << s << endl;
	return 0;
}
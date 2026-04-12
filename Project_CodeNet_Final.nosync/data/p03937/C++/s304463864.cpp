#include <bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ll long long int
using namespace std;
ll ans = 0, sum = 0, n, k, counter = 0, w, h;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(50, vector<ll>(50, INF));

int main()
{
	cin >> h >> w;
	vector<vector<char>> vc(50, vector<char>(50, 0));
	REP(i, h)
		REP(j, w)
		cin >> vc[i][j];
	ll px = 0, py = 0;
	queue<pair<ll,ll>> q;
	q.emplace(0, 0);
	while(!q.empty())
	{
		px = q.front().second;
		py = q.front().first;
		q.pop();
		if(px&&py)
			if(vc[py][px-1]=='#'&&vc[py - 1][px] == '#')
			{
				cout << "Impossible" << endl;
				return 0;
			}
		if(px==w-1&&py==h-1)
		{
			cout << "Possible" << endl;
			return 0;
		}
		if (vc[py + 1][px] == '#'&&vc[py][px + 1] == '#')
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if (vc[py][px + 1] == '#'&&px + 1 <= w) q.emplace(py, px + 1);
		if (vc[py + 1][px] == '#'&&py + 1 <= h) q.emplace(py + 1, px);
	}
	cout << "Impossible" << endl;
}
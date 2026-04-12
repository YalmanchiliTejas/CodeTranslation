#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) begin(a),end(a)
#define MS(m,v) memset(m,v,sizeof(m))
#define D10  fixed<<setprecision(10)
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> P;
typedef complex<double> Point;
typedef long long ll;
const int INF = 1145141919;
const int MOD = 100000007;
const double EPS = 1e-10;
const double PI = acos(-1.0);
struct edge
{
	int from, to, cost;
	bool operator < (const edge& e) const { return cost < e.cost; }
	bool operator > (const edge& e) const { return cost > e.cost; }
};
///*************************************************************************************///
///*************************************************************************************///
///*************************************************************************************///
char c;
int main()
{
	map<char, int> t;
	FOR(i, 2, 10) t[i + '0'] = i;
	t['T'] = 10; t['J'] = 11; t['Q'] = 12; t['K'] = 13; t['A'] = 14;
	while (cin >> c, c!='#')
	{
		string s[4][13];
		REP(i, 4)REP(j, 13) cin >> s[i][j];
		int ns = 0; int ew = 0;
		int par = 0;
		REP(j,13)
		{
			string win = s[par][j];
			REP(i, 4)
			{
				if (s[i][j][1] == c)
				{
					if (win[1]!=c||t[win[0]] < t[s[i][j][0]]) win = s[i][j];
				}
				else if (win[1]!=c&&s[i][j][1] == s[par][j][1])
				{
					if ((win[1]!=c&&s[par][j][1]!=win[1])||t[win[0]] < t[s[i][j][0]]) win = s[i][j];
				}
				else
				{
					if (win[1] != c&&win[1]!=s[par][j][1])
					{
						if (t[win[0]] < t[s[i][j][0]]) win = s[i][j];
					}
				}
			}
			REP(i, 4)
			{
				if (win == s[i][j])
				{
					if (i % 2) ew++;
					else ns++;
					par = i;
				}
			}
		}
		cout << (ns > ew ? "NS" : "EW") << " " << max(ns, ew) - 6 << endl;
	}

	return 0;
}
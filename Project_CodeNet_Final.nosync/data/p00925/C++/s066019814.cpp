#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) begin(a),end(a)
#define MS(m,v) memset(m,v,sizeof(m))
#define D10  fixed<<setprecision(5)
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<short, short> P;
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


int main()
{
	string s; int n;
	cin >> s >> n;
	ll mul = 0; ll ltr = s[0]-'0';
	int l = s.size();
	FOR(i,2, l)
	{
		if (isdigit(s[i]))
		{
			if (s[i - 1] == '+') ltr += s[i]-'0';
			else ltr *= s[i]-'0';
		}
	}
	vector<ll> v;
	REP(i, l)
	{
		if (isdigit(s[i])) v.push_back(s[i] - '0');
		else if (s[i] == '+') v.push_back(-1);
		else v.push_back(-2);
	}
	bool update = true;
	while (update)
	{
		update = false;
		REP(i, v.size())
		{
			if (v[i] == -2)
			{
				update = true;
				v[i - 1] = v[i - 1] * v[i + 1];
				v.erase(v.begin() + i);
				v.erase(v.begin() + i);
			}
		}
	}
	REP(i, v.size()) if (v[i] >= 0) mul += v[i];

	if (n == mul&&n == ltr) puts("U");
	else if (n == mul) puts("M");
	else if (n == ltr) puts("L");
	else puts("I");
	return 0;
}
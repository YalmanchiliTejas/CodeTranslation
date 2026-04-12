#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-10;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

string s;
int n;

int mpar()
{
	vi v;
	v.push_back(s[0] - '0');
	FOR(i, 1, s.size())
	{
		if (s[i] == '+') v.push_back(s[i+1] - '0');
		else v.back() *= s[i + 1] - '0';
		i++;
	}
	int ans = 0;
	REP(i, v.size()) ans += v[i];
	return ans;
}

int lpar()
{
	int ans = s[0]-'0';
	FOR(i, 1, s.size())
	{
		int t = s[i + 1] - '0';
		if (s[i] == '+') ans += t;
		else ans *= t;
		i++;
	}
	return ans;
}

int main()
{
	cin >> s >> n;
	int l = lpar();
	int m = mpar();
	char c;
	if (l==n&&m==n) c = 'U';
	else if (l == n) c = 'L';
	else if (m == n) c = 'M';
	else c = 'I';
	cout << c << endl;
	return 0;
}
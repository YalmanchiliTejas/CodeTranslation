#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

vs dec(string s)
{
	vs res;
	string t;
	for (auto c : s)
	{
		if (c == '/')
		{
			res.push_back(t);
			t.clear();
		}
		else if (c == 'b')
		{
			t.push_back('b');
		}
		else if (isdigit(c))
		{
			REP(i, c - '0') t.push_back('.');
		}
		else assert(false);
	}
	res.push_back(t);
	return res;
}

string enc(string s)
{
	string res;
	int cnt = 0;
	for (auto c : s)
	{
		if (c == '.') cnt++;
		else
		{
			if (cnt != 0) res.push_back('0' + cnt);
			res.push_back('b');
			cnt = 0;
		}
	}		
	if (cnt != 0) res.push_back('0' + cnt);
	return res;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	string s;
	while (cin >> s, s != "#")
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		vs fld = dec(s);
		fld[a][b] = '.';
		fld[c][d] = 'b';
		REP(i, fld.size()) cout << enc(fld[i]) << (i == fld.size() - 1 ? "\n" : "/");
	}
	return 0;
}
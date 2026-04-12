#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>

#define REP(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define ALLOF(c) c.begin(), c.end()
#define RANGEOF(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define EPS 1e-9
#define INF 1000000000
using namespace std;

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i,n) { v.push_back(read<T>()); } return v; }
template <class T> vector<vector<T>> read(int n, int m)
{
	vector<vector<T>> v;
	REP(i,n) { v.push_back(read<T>(m)); }
	return v;
}

template <class T> void write(const T &t) { cout << t << endl; }
template <class T> void write(const T &t, const T &t2) { cout << t << ' ' << t2 << endl; }
template <class T> void write(const vector<T> &v)
{
	ostringstream ss; 
	for (auto x : v) ss << x << ' ';
	auto s = ss.str();
	cout << s.substr(0, s.length() - 1) << endl;
}

struct _Reader { template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
#define READ(t,...) t __VA_ARGS__; _Reader(), __VA_ARGS__

void solve();
int main() { solve(); return 0; }

/// template end ///



void solve()
{
	while (true)
	{
		READ(string, s);
		if (s == "#") { break; }
		struct pred
		{
			static bool left(char c) { return strchr("qwertasdfgzxcvb", c); }
			static bool right(char c) { return strchr("yuiophjklnm", c); }
		};
		replace_if(ALLOF(s), pred::left, 'L');
		replace_if(ALLOF(s), pred::right, 'R');
		s.erase(unique(ALLOF(s)), s.end());
		write(s.length() - 1);
	}
}
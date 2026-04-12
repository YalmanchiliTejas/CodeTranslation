#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

using namespace std;

int main(int argc, char** argv) 
{
#ifdef HOME
	if(IsDebuggerPresent())
	{
		freopen("../in.txt", "rb", stdin);
		freopen("../out.txt", "wb", stdout);
	}
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	int64_t N, X, M;
	cin >> N >> X >> M;
	vector<int64_t> v(M,0),w(M, -1);
	if (X == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int64_t su = 0;
	int64_t curr = 0;
	while (w[X] == -1)
	{
		v[X] = su;
		w[X] = curr;
		su += X;
		X = (X * X) % M;
		++curr;
		if (curr == N)
		{
			cout << su << endl;
			return 0;
		}
 	}
	int64_t dist = curr - w[X];
	int64_t sud = su - v[X];
	int64_t re = (N - curr) / dist;
	curr += re * dist;
	su += re * sud;
	while (curr < N)
	{
		su += X;
		X = (X * X) % M;
		++curr;
	}
	cout << su << endl;
	return 0;
}

#include <bits/stdc++.h>
#define endl '\n'

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int n;
int x[MAXN];

void read()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i];
}

void solve()
{
	vector<int> actual;
	for(int i = 0; i < n; i++)
		actual.push_back(x[i]);

	sort(actual.begin(), actual.end());

	for(int i = 0; i < n; i++)
	{
		int v = actual[n / 2 - 1]; 
		if(x[i] <= v) v = actual[n / 2];
		cout << v << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}


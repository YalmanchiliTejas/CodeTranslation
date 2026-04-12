//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	int n;
	cin >> n;
	vector < pair < int, int > > a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	//~solve
	vector < int > ans(n);
	sort(all(a));
	int k = n / 2 - 1;
	for (int i = 0; i < n; i++)
	{
		if (i > k)
		{
			ans[a[i].second] = a[k].first;
		}		
		else
		{
			ans[a[i].second] = a[k + 1].first;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}


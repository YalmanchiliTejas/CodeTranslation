#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef vector<string> vs;
typedef vector<vs> vvs;

typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

typedef map<string, int> msi;

typedef pair<int, int> pii;
typedef pair <ll, ll> pll; // note 'single' ls

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)

#define pb \
push_back

#define ff \
first

#define ss \
second

int main()
{
	int n;
	cin >> n;

	vector<pair<ll, int>> X;

	REP(i, 0, n-1)
	{
		ll x;
		cin >> x;

		X.pb({ x, i });
	}

	sort(X.rbegin(), X.rend());

	ll median_one = X[(n / 2) - 1].first;
	ll median_two = X[(n / 2)].first;

	vll print_out(n);

	for (int i=0; i<X.size(); i++)
	{
		pair<ll, int> x = X[i];

		if (i <= (n / 2) - 1) print_out[x.second] = median_two;
		else print_out[x.second] = median_one;
	}

	for (auto x : print_out)
	{
		cout << x << endl;
	}

	//cout << median_one << " " << median_two << endl;

	//cin >> n;
	return 0;
}
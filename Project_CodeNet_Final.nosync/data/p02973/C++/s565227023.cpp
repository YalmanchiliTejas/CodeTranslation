#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#include"bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define ends ' '
#define endl '\n'
#define pb emplace_back
#define x first
#define y second
#define pii pair<int, int>
#define sz(x) (int)(x).size()

vector<vector<int>> h;
vector<int> G;
vector<vector<int>>mn;

const int prime = 1e9+7;

int mod(int a, int p = prime) { return (a%p + p) % p; }

deque<int> D;

void f(vector<int> &mn, vector<int> &h, int &b)
{
	D.clear();
	for(int i = 1; i <= b; ++i)
	{
		while(!D.empty() and h[D.back()] >= h[i])
			D.pop_back();
		D.push_back(i);
	}

	mn[b] = h[D.front()];

	for(int i = b+1; i < mn.size(); ++i)
	{
		if(D.front() <= i-b)
			D.pop_front();
		while(!D.empty() and h[D.back()] >= h[i])
			D.pop_back();
		D.push_back(i);
		mn[i] = h[D.front()];
	}
}


int32_t main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	IOS;

	int n;
	
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	reverse(a.begin(), a.end());

	multiset<int> ms;

	for(int i = 0; i < n; ++i)
	{
		ms.insert(a[i]);
		auto it = ms.upper_bound(a[i]);
		if(it != ms.end())
			ms.erase(it);
	}

	cout << ms.size();

	return 0;
}
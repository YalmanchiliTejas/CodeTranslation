#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], b[N];

int get1()
{
	for(int i = 1; i <= n; i++)
	{
		if(i % 2)
			b[i] = 1;
		else
			b[i] = 100;
	}
	vector<int> vals, have;
	for(int i = 1; i <= n; i++)
	{
		int val = 0;
		if(i - 1 >= 1 && b[i] > b[i - 1])
			val++;
		else if(i - 1 >= 1)
			val--;
		if(i + 1 <= n && b[i] < b[i + 1])
			val--;
		else if(i + 1 <= n)
			val++;
		vals.push_back(val);
		have.push_back(a[i]);
	}
	sort(vals.rbegin(), vals.rend());
	sort(have.rbegin(), have.rend());
	//1 100 1 100
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += have[i] * vals[i];
	return ans;
}

int get2()
{
	for(int i = 1; i <= n; i++)
	{
		if(i % 2)
			b[i] = 100;
		else
			b[i] = 1;
	}
	vector<int> vals, have;
	for(int i = 1; i <= n; i++)
	{
		int val = 0;
		if(i - 1 >= 1 && b[i] > b[i - 1])
			val++;
		else if(i - 1 >= 1)
			val--;
		if(i + 1 <= n && b[i] < b[i + 1])
			val--;
		else if(i + 1 <= n)
			val++;
		vals.push_back(val);
		have.push_back(a[i]);
	}
	sort(vals.rbegin(), vals.rend());
	sort(have.rbegin(), have.rend());
	//1 100 1 100
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += have[i] * vals[i];
	return ans;
}


int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = max(get1(), get2());
	cout << ans;
	return 0;
}
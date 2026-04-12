#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>

using namespace std;

int main()
{
	int a[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 1;
	int k = a[0];
	for (int i = 1; i < n; i++)
	{
		if (k <= a[i])
		{
			ans++;
			k = a[i];
		}
	}
	cout << ans << endl;
}
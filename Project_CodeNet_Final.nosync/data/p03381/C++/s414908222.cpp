#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string> 
#include <map>
#include <iomanip>
#include <list>
#include <stack>

using namespace std;


typedef int INT;
#define int long long

INT main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		a[i] = { b, i };
	}
	sort(a.begin(), a.end());

	int m = n / 2 - 1;
	vector <int> c(n);
	for (int i = 0; i < n; i++)
	{
		if (i <= m)
			c[a[i].second] = a[m + 1].first;
		else
			c[a[i].second] = a[m].first;
	}
	for (int i = 0; i < n; i++)
		cout << c[i] << endl;


	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, p[100], i, s;
	while (cin >> n && n)
	{
		for (i = 0; i < n; i++)
			cin >> p[i];
		sort(p, p+n);
		for (i = 1, s = 0; i < n-1; i++)
			s += p[i];
		cout << s / (n-2) << endl;
	}
}
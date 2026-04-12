#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, *a;
	cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++) cin >> a[i];
	 
	int q, o;
	cin >> q;
	while (q--)
	{
		cin >> o;
		cout << lower_bound(a, a + n, o) - a << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
	cin >> n;
	x = n / 15 * 200;
	n *= 800;
	n -= x;
	cout << n << endl;
	return 0;
 } 
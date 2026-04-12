#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,x,t = 1;
int main()
{
	cin >> a >> b >> c;
	x = b * 10 + c;
	if (x % 4 == 0) cout << "YES\n";
		else cout << "NO\n";
 	return 0;
 } 
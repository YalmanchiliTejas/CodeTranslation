#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	int ans = r*100+g*10+b;
	if (ans%4 == 0) puts("YES");
	else puts("NO");
	return 0;
}
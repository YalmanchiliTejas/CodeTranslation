#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r1, r2;
	cin >> r1 >> r2;
	double ans = r1 * r2 / double(r1 + r2);
	printf("%.10f", ans);
}
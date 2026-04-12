#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int r, g, b, s;
	cin >> r >> g >> b;
	s = r * 100 + g * 10 + b;
	cout << (s % 4 == 0 ? "YES" : "NO");
	return 0;
}
#include<iostream>
#include <algorithm>
#include<string>
#include <bitset>
#include <vector>
#include <functional>
#include <climits>
#include <iomanip>
#include <utility>
using namespace std;
using ll = long long;
typedef pair <int, int> pii;

int main()
{

	//int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ans = 0;
	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, ans = 0;
	//cout << LONG_MAX << endl;
	string s[101];
	//long long n, A[1000000000];
	int n, m, q;
	//int   y[100001], z[100001], x[10001] = {};
	//pii y[100001];
	//pair<int, float> pii[100001];
	ll A[101] = {};
	ll B[101] = {};
	cin >> a;
	cin >> b;
	for (c = 0; c < a; c++)
	{
		cin >> s[c];
	}
	for (c = 0; c < a; c++)
	{
		for (d = 0; d < b; d++)
		{
			if (s[c][d] == '#')
			{
				break;
			}
			if (d == b - 1)
			{
				A[c] = 1;
			}
		}
	}
	for (c = 0; c < b; c++)
	{
		for (d = 0; d < a; d++)
		{
			if (s[d][c] == '#')
			{
				break;
			}
			if (d == a - 1)
			{
				B[c] = 1;
			}
		}
	}
	for (c = 0; c < a; c++)
	{
		for (d = 0; d < b; d++)
		{
			if (A[c] != 1 && B[d] != 1)
			{
				cout << s[c][d];
			}
		}
		if (A[c] != 1)
		{
			cout << endl;
		}
	}
	////std::cout << std::fixed;
	//cout << std::setprecision(20) << << endl;
	//cout << d+1 << endl;
	//cout << "" << endl;

	return 0;
}
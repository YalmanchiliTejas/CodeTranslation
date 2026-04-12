#include<iostream>
#include <algorithm>
#include<string>
#include <bitset>
#include <vector>
#include <functional>
#include <climits>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <numeric>
using namespace std;
using ll = long long;

typedef pair <int, int> pii;

int main()
{

	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ans = 0;
	//cout << LONG_MAX << endl;
	//long long n, A[1000000000];
	//ll n, m, q;
	cin >> a;
	string s[51];
	for (int i = 0; i < a; i++)
	{
		cin >> s[i];
	}
	char memo[51][30] = { {} };
	for (int i = 0; i < a; i++)
	{
		for (int k = 0; k < s[i].length(); k++)
		{
			//cout << s[i][k] - 'a'<<endl;
			memo[i][s[i][k] - 'a']++;
		}
	}
	char mini[30] = { {} };
	for (int i = 0; i < 26; i++)
	{
		mini[i] = memo[0][i];
	}
	for (int i = 1; i < a; i++)
	{
		for (int k = 0; k < 26; k++)
		{
			mini[k] = min(mini[k], memo[i][k]);
			
		}
	}
	char z;
	for (int i = 0; i < 26; i++)
	{
		while (mini[i]>0)
		{
			z = 'a' + char(i);
			//cout << z;
			cout << z;
			mini[i]--;
		}
	}
	cout<<endl;

	//-8965725 + (9912027 * (7812383 + 8965725)) / (4915988 + 9912027)
	//cout <<  << endl;

	////std::cout << std::fixed;
	//cout << std::setprecision(20) << << endl;
	//cout << d+1 << endl;
	//cout << "" << endl;

	return 0;
}
//accumulate(x, x + a, 0);
//memcpy(x, visited, sizeof(ll)*n);
//void kansuu(ll num, ll visited[10]) {}
//kansuu(1, zz);
//cout << setprecision(15) << v << endl;

//int temp;
//for (int i = 0; i < n - 1; i++) {
//	for (int j = n - 1; j > i; j--) {
//		if (w[j - 1] < w[j]) {  /* 前の要素の方が大きかったら */
//			temp = w[j];        /* 交換する */
//			w[j] = w[j - 1];
//			w[j - 1] = temp;
//		}
//	}
//}


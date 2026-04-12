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
int main()
{
	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	//ll n, m, h, w;
	//cin >> x;
	//string s, t;
	ll x[100005];
	ll y[100005];
	cin >> a;
	for (ll i = 0; i < a; i++)
	{
		cin >> x[i];
	}
	ll g = 0;
	y[0] = 1;
	c = -1;
	for (ll i = 1; i < a-1; i++)
	{
		y[i] = c * 2;
		c *= -1;
	}
	y[a - 1] = c;
	sort(x, x + a);
	sort(y, y + a);
	for (ll i = 0; i < a; i++)
	{
		b += x[i] * y[i];
	}
	
	y[0] = -1;
	c = 1;
	for (ll i = 1; i < a - 1; i++)
	{
		y[i] = c * 2;
		c *= -1;
	}
	y[a - 1] = c;
//	sort(x, x + a);
	sort(y, y + a);
	for (ll i = 0; i < a; i++)
	{
		d += x[i] * y[i];
	}

	//cout << abs(x[0] - x[a / 2]) << endl;
	cout <<max(b,d) << endl;


	//cout << sum << endl;
	//cout <<  endl;
	return 0;
}

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




//
//ll insuusyurui[1000] = {};
//ll insuukazu[1000] = {};
//ll memo[4000] = {};
//ll memo2[4000] = {};
//cin >> n;
//cin >> m;
//a = 2;
//// √n ≧ a ( n ≧ a * a ) の間ループ処理
//while (n >= a * a) {
//	// a で割り切れたら、a は素因数
//	// そして、割られる数を a で割る
//	// a で割り切れなかったら、 a を 1 増加させる
//	if (n % a == 0) {
//		printf("%lld * ", a);
//		insuukazu[c]++;
//		n /= a;
//	}
//	else {
//		a++;
//		//if (insuukazu[c] != 0)
//		{
//			c++;
//			//cout << c << endl;
//
//		}
//	}
//}
//printf("%lld\n", n);
//for (int i = 0; i < c; i++)
//{
//	//cout << insuukazu[i] << endl;
//}
//
//cout << "Yes" << endl;












//ll n, m;
//cin >> n;
//cin >> m;
//cin >> s;
//cin >> t;
//ll i;
//c = n;
//d = m;
//if (c<d)
//{
//	swap(c, d);
//}
//i = c % d;
//while (i != 0) {
//	c = d;
//	d = i;
//	i = c % d;
//}
//i = n*m / d;

//a = min(n, m);
//b = -1;
//for (ll z = 0; z < i; z++)
//{
//	if (z%m == 0&&z%n==0)
//	{
//		if (s[z / n] != t[z / m])
//		{
//			cout << -1 << endl;
//			return 0;
//		}
//	}


//	z += a;
//	z--;
//	/*
//	if (z % (i / n) == 0)
//	{
//	a++;
//	}
//	if (z % (i / m) == 0)
//	{
//	b++;
//	}
//	if (z % (i / n) == z % (i / m))
//	{
//	if (s[a] != t[b])
//	{
//	cout << -1 << endl;
//	return 0;
//	}
//	}
//	*/
//}

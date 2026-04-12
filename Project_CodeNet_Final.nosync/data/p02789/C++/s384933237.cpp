#include "bits/stdc++.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair <ll, ll > pll;

bool comp(const pll &a, const pll &b) {
	return a.first < b.first;
}
std::vector<int> enum_div(int n)//nの約数を列挙
{
	std::vector<int> ret;
	for (int i = 1; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			ret.push_back(i);
			if (i != 1 && i*i != n)
			{
				ret.push_back(n / i);
			}
		}
	}
	return ret;
}


template<int N>
int factorial() {
	return factorial<N - 1>() * N;
}

template<>  /// 特殊化：factorial<N=”1”>だったら，値を返す
int factorial<1>() {
	return 1;
}
int main()
{
	priority_queue<int> q;
	string s = {};
	string s1 = {};
	ll h = 0, w = 0, k = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, ans = 0;
	ll x[300005] = {};
	ll y[300005] = {};
	ll y2[302][302] = {};
	cin >> a;
	cin >> b;
	if (a==b)
	{
	//cout << ans << endl;
		cout << "Yes" << endl;

	}
	else
	{
		cout << "No" << endl;

	}

	//cout << ans << endl;



	//return 0;

	/*cout << c << endl;
	cout << b << endl;*/
	//cout << fixed << setprecision(10) <<tmp << endl;
	//cout<<factorial<10><<endl;
	return 0;
}
//2つの組の数をソートしたりするやつ
//vector<pair<ll, ll> > hoges(a);
//for (int i = 1; i <= a; i++)
//{
//	cin >> h;
//	hoges[i - 1] = make_pair(h, i);
//}
//sort(hoges.begin(), hoges.end(), comp);
//for (int i = 0; i < a; i++)
//{
//	cout << hoges[i].second << endl;
//}

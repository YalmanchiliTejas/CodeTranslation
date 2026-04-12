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
ll nCr(ll n, ll r);//コンビネーション
int permutation(int n, int r);//nPk パーミュテーション
int factorial(int k);//階乗

template<>  /// 特殊化：factorial<N=”1”>だったら，値を返す
int factorial<1>() {
	return 1;
}
int main()
{
	//priority_queue<int> q;
	string s = {};
	string s1 = {};
	ll h = 0, w = 0, k = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, ans = 0;
	ll x[105][4][2] = {};
	ll y[300005] = {};
	ll z[302][302] = {};
	ll n;
	cin >> s;
	n = s.size();
	ll K;
	cin >> K;
	x[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int d = 0; d < 10; d++)
				{
				ll ni=i+1, nj=j, nk=k;
				ll nd = s[i] - '0';
					if (d!=0)
					{
						nj++;
					}
					if (nj>K)
					{
						continue;
					}
					if (k==0)
					{
						if (d>nd)
						{
							continue;
						}
						if (d<nd)
						{
							nk = 1;
						}
					}
					x[ni][nj][nk] += x[i][j][k];
				}
			}
		}
	}


	cout << x[n][K][0] +x[n][K][1] << endl;



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

int permutation(int n, int r) {
	int n_sum, r_sum;
	int i;
	r = n - r;
	n_sum = factorial(n);
	r_sum = factorial(r);
	return n_sum / r_sum;
}

ll nCr(ll n, ll r) {
	ll ans = 1;
	for (ll i = n; i > n - r; --i) {
		ans = ans * i;
	}
	for (ll i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}
int factorial(int k) {
	int sum = 1;
	for (int i = 1; i <= k; ++i)
	{
		sum *= i;
	}
	return sum;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod = 1000000007;
ll gcd(ll a, ll b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int d[2000];
int main()
{
	int num;
	scanf("%d", &num);
	fill(d, d + 2000, 1000);
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		int x[2000];
		fill(x, x + 2000, 0);
		for (int j = 0; j < s.size(); j++)x[s[j]]++;
		for (int j = 'a'; j <= 'z'; j++)d[j] = min(d[j], x[j]);
	}
	string r;
	for (int i = 'a'; i <= 'z'; i++)for (int j = 0; j < d[i]; j++)r.push_back(i);
	cout << r << endl;
}
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
int d[10][10];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		d[za][zb] = d[zb][za] = 1;
	}
	vector<int>v;
	for (int i = 0; i < num; i++)v.push_back(i);
	int r = 0;
	for (;;)
	{
		bool f = true;
		for (int i = 0; i < num - 1; i++)if (d[v[i]][v[i + 1]] == 0)f = false;
		if (f&&v[0] == 0)r++;
		if (!next_permutation(v.begin(), v.end()))break;
	}
	printf("%d\n", r);
}
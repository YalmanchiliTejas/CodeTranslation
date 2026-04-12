//#include<bits/stdc++.h>
#include<queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#define E (2.71828182)
#define PI (3.1415926535898)
#define	max(a,b)	((a)>(b)?(a):(b))
#define	min(a,b)	((a)>(b)?(b):(a))
#define	mem(a,b)	memset(a,b,sizeof(a))
#define	_max(a,b,c)	(max(a,b)>c?max(a,b):c)
#define mod	1000000007
#include<set>
#define gc getchar
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
const long long  MAX_V = 5005, INF = 2147483647, MOD = 100000007;
#include <iostream>
using namespace std;

int n;
ull a[56], sum;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];	
	}	
	while (1)
	{
		ull b[55] = {0};
		ull maxn = n - 1;
		ull temp = 0;
		for (int i = 0; i < n; i++)
		{
				if (a[i] > maxn)
				{
					b[i] = a[i] / n;
					temp += b[i];
					a[i] %= n;
				}
		}
		if (!temp) break;
		for (int i = 0; i < n; i++)
		{
			if (b[i])
			{
				a[i] += temp - b[i];
			}
			else
			{
				a[i] += temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum -= a[i];
	}
	cout << sum << endl;
} 
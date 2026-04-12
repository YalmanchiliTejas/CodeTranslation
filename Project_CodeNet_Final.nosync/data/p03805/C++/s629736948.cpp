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
using namespace std;
using ll = long long;
ll n, m;
ll sum = 0;
	ll memo[50][50] = {};
void kansuu(ll num, ll visited[10]) {
	ll flag = 0;
	for (int i = 2; i <= n; i++)
	{
		if (visited[i]==0)
		{
			flag = 1;
		}
	}
	if (flag==0)
	{
		sum++;
		return;
	}
			ll x[10] = {};
	for (ll i = 1; i <= n; i++)
	{
		if (memo[num][i]==1&&visited[i]==0)
		{
			memcpy(x, visited, sizeof(ll)*10);
			/*cout << "x=" ;
			for (ll z = 1; z <= n; z++)
			{
				cout << x[z];
			}
			cout << endl;
			cout << "visited=";
			for (ll z = 1; z <= n; z++)
			{
				cout << visited[z];
			}
			cout << endl;
			cout << endl;
*/
			x[i]=1;
			kansuu(i, x);
		}
	}
	
}
int main()
{
	ll a, b = 0, c = 0, d = 0;
	ll l;
	char C[1000][1000] = {};
	ll h, w, sy, sx, gy, gx;
	queue<int> x, y;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;
		memo[a][b] = 1;
		memo[b][a] = 1;
	}
	ll zz[10] = {};
	zz[1] = 1;
	kansuu(1,zz);


	cout << sum << endl;

	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack> 
#include <set>
#include <map>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int INF = 1000000002;
const int mod = 1000000007;

#define N 200010

deque<int> Q;

int a[N];

int main()
{
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int n, x;
	scanf("%d", &n);
	scanf("%d", &x);
	Q.push_back(x);

	bool rev = false;
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &x);
		if (!rev) Q.push_back(x);
		else Q.push_front(x);
		rev ^= 1; 
	}

	if (!rev)
	{
		for (int i = 1; i <= n; ++i)
		{
			x = Q.front();
			Q.pop_front();
			printf("%d%c", x, i == n? '\n':' ');
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			x = Q.back();
			Q.pop_back();
			printf("%d%c", x, i == n? '\n':' ');
		}
	}

	return 0;
}


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long n, p = 1e9+7;
long dp[5003][5003];
long sum[5003];
long f(long x, long y)
{
	if(x == y) return 1;
	else if(x < y || x == 0 || y == 0) return 0;
	else if(dp[x][y]) return dp[x][y];
	else return dp[x][y] = (y*f(x-1, y) + f(x-1,y-1))%p;
}

long xxx[5003][5003];
long C(long x, long y)
{
	if(x == 0 && y == 0) return 1;
	else if(x < y || y < 0) return 0;
	else if(xxx[x][y]) return xxx[x][y];
	else return xxx[x][y] = (C(x-1,y)+C(x-1,y-1))%p;
}

long pw(long x, long y, long mod)
{
	if(y == 0) return 1;
	else if(y&1) return (pw(x,y-1,mod)*x)%mod;
	else
	{
		long temp = pw(x,y/2,mod);
		return (temp*temp)%mod;
	}
}

long s(long x, long y)
{
	long res = 0;
	for(int i = y; i <= x; i++)
	{
		res += (C(x,i)*f(i,y))%p;
		res %= p;
	}
	return res;
}
void print()
{
	for(int i = 0; i <= 10; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%lld " , s(i,j));
		printf("\n");
	}
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	// print();
	scanf("%lld %lld", &n, &p);
	long res = 0;
	for(int i = 0; i <= n; i++)
	{
		long temp = (C(n,i)*pw(2,pw(2,n-i,p-1),p))%p;
		long temp2 = 0;
		for(int j = 0; j <= i; j++)
		{
			temp2 += ((f(i+1,j+1))*pw(2, j*(n-i),p))%p;
			temp2 %= p;
		}
		temp = (temp*temp2)%p;
		// printf("%lld %lld\n", temp2, temp);
		if(i&1) res -= temp;
		else res += temp;
		res %= p;
	}
	printf("%lld\n", (res+p)%p);
}

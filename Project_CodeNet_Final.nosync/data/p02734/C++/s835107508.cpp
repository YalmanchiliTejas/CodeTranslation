#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define MAXN 3005
const long long a = 998244353;
long long w[MAXN];
long long f[MAXN];
using namespace std;
long long n;
long long m;
long long sum = 0;

void dfs()
{
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1;i <= n; i++)
	{
		for (int j = m;j >= w[i];j--)
		{
			f[j] = (f[j] + f[j - w[i]]) % a;
		}
		sum = (sum + f[m]) % a;
		f[0]++;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> w[i];
	}
	dfs();
	cout << sum;
	return 0;
}
#include <bits/stdc++.h>
#define X first
#define Y second
#define LL long long
#define MP make_pair
#define PB push_back
#define SZ(a) (LL)(a.size())
const LL INF = 1000 * 1000 * 1000 + 47;
const LL LINF = INF * (LL)INF;
using namespace std;
const int MAX = 3005;
//int f[100005];

int N , mod;
int ways[MAX];
int ways2[MAX][MAX];

int pw2pw2[MAX * MAX ];
int pw2[MAX * MAX];
int c[MAX][MAX];
int add(int a, int b)
{
	return a + b >= mod ? a + b - mod : a + b;
}
int sub(int a , int b)
{
	return a - b < 0 ? a - b + mod : a - b;
}
int mult(int a , int b)
{
	return a * (LL)b % mod;
}
void init()
{
	ways2[0][0] = 1;
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			ways2[i + 1][j] = add(ways2[i + 1][j] , mult(ways2[i][j] , j + 1));
			ways2[i + 1][j + 1] = add(ways2[i + 1][j + 1] , ways2[i][j]);
		}
	}
	for(int i = 0; i < MAX; i++)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = add(c[i - 1][j - 1] , c[i - 1][j]);
	}
	pw2[0] = 1;
	pw2pw2[0] = 2;
	for(int i = 1; i < MAX * MAX; i++)
	{
		pw2[i] = mult(pw2[i - 1] , 2);
		pw2pw2[i] = mult(pw2pw2[i - 1] , pw2pw2[i - 1]);
	}
	
}
int main() 
{
	ios_base::sync_with_stdio(0);
	
	cin >> N >> mod;
	init();
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= i; j++)
			ways[i] = add(ways[i] , mult(ways2[i][j] , mult(pw2[j * (N - i)] , pw2pw2[N - i])));
		//cout << ways[i] << endl;
	}
	int ans = 0;
	for(int i = 0; i <= N; i++)
		if(i & 1)
			ans = sub(ans , mult(ways[i] , c[N][i]));
		else
			ans = add(ans , mult(ways[i] , c[N][i]));
	cout << ans;
	
}

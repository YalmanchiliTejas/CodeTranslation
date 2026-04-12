#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int INF = 1000 * 1000 * 1000;
const ll LINF = (ll)INF * INF;
int A , B;
int d[11][11];
int f[101][101];
int dist[202];

int main()
{
	//freopen("input.txt" , "r" , stdin);
	//freopen("output.txt" , "w" , stdout);
	cin >> A >> B;
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++)
		{
			cin >> d[i][j];
		}
	for(int a = 0; a <= 100; a++)
		for(int b = 0; b <= 100; b++)
		{
			for(int x = 1; x <= A; x++)
				for(int y = 1; y <= B; y++)
				{
					f[a][b] = max(f[a][b] , d[x][y] - x * a - y * b);
				}
		}
	bool good = true;
	for(int x = 1; x <= A; x++)
		for(int y = 1; y <= B; y++)
		{
			for(int i = 0; i < 202; i++)
				dist[i] = INF;
			for(int i = 0; i <= 100; i++)
				dist[i] = x * i;
			for(int i = 100; i >= 0; i--)
			{
				if(i != 100)
					dist[i + 101] = dist[i + 1 + 101] + y;
				for(int j = 0; j <= 100; j++)
					dist[i + 101] = min(dist[i + 101] , f[j][i] + dist[j]);
			}
			if(dist[101] != d[x][y])
				good = false;
		}

	if(good)
	{
		printf("Possible\n");
		int n = 202;
		printf("%d %d\n" , n ,  (n - 2) + n * n / 4);
		for(int i = 1; i <= 100; i++)
		{
			printf("%d %d X\n" , i - 1 + 1 , i + 1);
			printf("%d %d Y\n" , i + 101 + 1 , i + 101 - 1 + 1);
		}
		for(int i = 0; i <= 100; i++)
		{
			for(int j = 0; j <= 100; j++)
			{
				printf("%d %d %d\n" , i + 1 , j + 101 + 1 , f[i][j]);
			}
		}
		printf("1 102\n");
	}
	else
		printf("Impossible\n");
}

#include <bits/stdc++.h>
#define eps 1e-7
#define e 1e-3
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef vector<int> lnum;
const int INF = 4*1000*1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const int base = 1000*1000*1000;

char field[10][10];
int n , m;
int cnt = 0;
int main()
{
	scanf("%d %d\n" , &n , &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%c" , &field[i][j]);
			cnt += field[i][j] == '#';
		}
		scanf("\n");
	}
	if(cnt == n + m - 1)
	{
		cout << "Possible";
	}
	else
		cout << "Impossible";
    return 0;
}

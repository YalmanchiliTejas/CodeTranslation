#include <bits/stdc++.h>
using namespace std;

const int N = 0;
int n,m;
int mat[10][10];

bool valid(int a[])
{
	for(int i=1;i<n;i++)
	{
		if(mat[a[i-1]][a[i]] == 1) continue;
		else return false;
	}
	return true;
}


int main()
{
	int a[8];
	cin >> n >> m;
	for(int i=0,x,y;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		y--; x--;
		mat[x][y]++;
		mat[y][x]++;
	}
	
	for(int i=0;i<n;i++)
	{
		a[i] = i;
	}
	
	int ans = 0;
	do
	{
		if(valid(a))
		{
			ans++;
		}
	}while(next_permutation(a+1,a+n));
	
	cout << ans;
}


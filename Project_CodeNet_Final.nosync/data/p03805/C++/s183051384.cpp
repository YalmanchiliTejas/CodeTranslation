#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int map[10][10];
int memo[10];
int ans=0;

void dfs(int d,int cur)
{
	memo[cur]=1;
	
	if(d==N-1)
	{
		int x=1;
		for(int i=0;i<N;i++)
			x=x&memo[i];
		if(x==1)ans++;
		memo[cur]=0;
		return;
	}
	
	for(int i=0;i<N;i++)
	{
		if(memo[i]==0 && map[cur][i])
		{
			dfs(d+1,i);
		}
	}
	memo[cur]=0;
	return;
}

int main()
{
	int a,b;
	
	cin >> N >> M;
	
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--;
		b--;
		map[a][b]=1;
		map[b][a]=1;
	}
	
	dfs(0,0);
	
	cout << ans << endl;
	return 0;
}

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

vector<int> graph[8];

int dfs(int n,int m, bool *vis)
{
	if(count(vis,vis+n,true)==n)
		return 1;
	int ans = 0;
	for(int it:graph[m])
		if(!vis[it])
		{
			vis[it]= 1;
			ans += dfs(n,it,vis);
			vis[it]= 0;
		}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i= 0; i<m;i++)
	{
		int g,h;
		cin>>g>>h ,--g,--h;
		graph[g].push_back(h);
		graph[h].push_back(g);
	}
	bool vis[n]={0};
	vis[0]=1;
	cout<<dfs(n,0,vis)<<endl;
	return 0;
}
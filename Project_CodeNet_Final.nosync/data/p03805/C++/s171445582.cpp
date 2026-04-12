#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#define lld long long int
#define DBG1(vari1) cerr<<#vari1<<" = "<<(vari1)<<endl;
#define DBG2(vari1,vari2) cerr<<#vari1<<" = "<<(vari1)<<" "<<#vari2<<" = "<<(vari2)<<endl;
#define DBG3(vari1,vari2,vari3) cerr<<#vari1<<" = "<<(vari1)<<" "<<#vari2<<" = "<<(vari2)<<" "<<#vari3<<" = "<<(vari3)<<endl;
using namespace std;
int visited[100];
vector <int> adj[100];
int ans=0;
int nv=0;
int n,m;
void dfs(int s)
{
	visited[s]=1;
	nv++;
	if(nv==n)
		ans++;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
	visited[s]=0;
	nv--;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);  
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << ans;
}
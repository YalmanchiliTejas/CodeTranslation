#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int maxn=2010;

vector<int> s[maxn];
int n,m;
int sum;
int vis[maxn];

void dfs(int cnt,int num)
{
    if(num==n)
    {
        sum++;
        return;
    } 
    for(int i=0;i<s[cnt].size();i++)
    {
        if(vis[s[cnt][i]]==0)
        {
            vis[s[cnt][i]]=1;
            dfs(s[cnt][i],num+1);
            vis[s[cnt][i]]=0;
        }
    }
}
int main()
{
	int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            cin >> a >> b;
            s[a].push_back(b);
            s[b].push_back(a);
        }
        sum=0;
        vis[1]=1;
        dfs(1,1);
        cout << sum << endl;
    }
    return 0;
}
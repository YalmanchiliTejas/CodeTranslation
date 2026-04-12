/*
定义叶子节点为必胜点
一个点的胜败情况为：所有子节点异或起来然后取反
如果一个点有两个子节点都是必胜那么就是First 
*/ 
#include<bits/stdc++.h>
#define N 500005
using namespace std;
int head[N],son[N],father[N];
bool dp[N];
int n,x,y;
struct Tree{
    int nxt,to;
}e[500005];
int k=0;
void add(int x,int y){e[++k].nxt=head[x];e[k].to=y;head[x]=k;}
void dfs2(int u,int fa)
{
    son[u]=1;
    for (int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if (v==fa) continue;
        dfs2(v,u);
        son[u]=son[u]+son[v]; father[v]=u;
    }
}
bool flag=false;
void dfs(int u,int fa)
{
    if (son[u]==1){
    	dp[u]=true;
    	return;
	}
	int tot=0;
    if (flag) return;
    for (int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if (v==father[u]) continue;
        dfs(v,u);
        if (dp[v]==true) tot++;
        if (tot>=2){
            flag=true;
            return;
        }
        dp[u]=dp[u]^dp[v];
    }
    dp[u]=!dp[u];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs2(1,-1); dfs(1,-1);
    if (flag||dp[1]) puts("First");
    else puts("Second");
    return 0;
}
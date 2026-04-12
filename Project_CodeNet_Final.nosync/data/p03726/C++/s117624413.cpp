/*
    f[x]表示以x为根的子树中，先把x染成白之后对方下一步是否会在x子树中操作 
    g[x]表示以x为根的子树中，先手是否能获得胜利。
    
    当我们枚举致胜节点为root时，先手能赢当且仅当g[root]=1. 
	
	初始化(对于单点)：
	     g[x]=1;
	     f[x]=0;
	
	
	转移：
	    1.f[x]等于所有儿子的g的位或
		 
		 这个不难理解，因为只要有一个儿子的g为1的话，我们先把x染白，
		 对方一定会在g为1的这个子树中操作，不然就输了。
		 
		2.g[x]等于所有儿子的f的位与
		
		 这个也不难理解，因为只有所有儿子的f都为1了，我们才可以依次把每个儿子染白
		 最后依然有先手优势来染x，然后就赢了hhhh
	
	考虑上述算法仅适用于根固定的情况 ，我们可以把它扩展一下，
	第一遍dfs预处理以某个节点为根的函数值，
	第二遍dfs在每个节点O(1)计算出函数值。 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#define ll long long
#define maxn 100005
#define pb push_back
using namespace std;
vector<int> son[maxn];
int n,m,g[maxn];
int f[maxn];
bool win=0;

void dfs1(int x,int fa){
	int sz=son[x].size()-1,to;
	f[x]=0,g[x]=1;
	
	for(int i=0;i<=sz;i++){
		to=son[x][i];
		if(to==fa) continue;;
		dfs1(to,x);
		f[x]|=g[to],g[x]&=f[to];
	}
}

void dfs2(int x,int fa,int fa_f,int fa_g){
	int sz=son[x].size()-1,to;
	int hzf[sz+2],hzg[sz+2];
	hzf[sz+1]=1,hzg[sz+1]=0;
	
	if(g[x]&fa_f) win=1;
	
	for(int i=sz;i>=0;i--){
		hzf[i]=hzf[i+1];
		hzg[i]=hzg[i+1];
		to=son[x][i];
		if(to==fa) continue;
		
		hzf[i]&=f[to];
		hzg[i]|=g[to];
	}
	
	for(int i=0;i<=sz;i++){
		to=son[x][i];
		if(to==fa) continue;
		
		dfs2(to,x,fa_g|hzg[i+1],fa_f&hzf[i+1]);
		fa_g|=g[to];
		fa_f&=f[to];
	}
}

int main(){
	int uu,vv;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&uu,&vv);
		son[uu].pb(vv);
		son[vv].pb(uu);
	}
	
	dfs1(1,0);
	dfs2(1,0,1,0);
	
	if(win) puts("First");
	else puts("Second");
	
	return 0;
}
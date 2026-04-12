#include<bits/stdc++.h>
using namespace std;
const int nn=1e5+10;
bool f[nn];
vector<int>son[nn];
int fa[nn];
bool dfs(int p){
	for(int i=0,t;i<son[p].size();i++)
	if((t=son[p][i])!=fa[p]){
		fa[t]=p,dfs(t);
		if(f[p])f[p]^=f[t];
		else if(f[t])printf("First"),exit(0);
	}return f[p];
}int main(){
  	int n;
	scanf("%d",&n);
	memset(f,true,sizeof f);
	for(int i=1,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		son[a].push_back(b);
		son[b].push_back(a);
	}if(dfs(1))printf("First");
	else printf("Second");
	return 0;
}
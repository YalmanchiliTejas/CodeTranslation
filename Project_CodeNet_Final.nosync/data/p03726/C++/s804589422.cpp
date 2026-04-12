#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n,u,v;
bool win=false;
vector <int> to[maxn];
int dfs(int now,int fa){
	int siz=to[now].size(),cnt=0;
	for(int i=0;i<siz;i++){
		int t=to[now][i];
		if(t==fa) continue;
		cnt+=dfs(t,now);
	}
	if(fa==0&&cnt==0) win=true;
	if(cnt==1) return 0;
	if(cnt==0) return 1;
	win=true;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1,0);
	if(win){printf("First\n");}
	else{printf("Second\n");}
	return 0;
}
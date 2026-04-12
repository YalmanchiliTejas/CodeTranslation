#include<bits/stdc++.h>
using namespace std;
vector<int> v[25];
int n,m,a,b,cnt=0,data[20];
void dfs(int st,int lv){
	//printf("%d %d\n",st,lv);
	if(lv==n-1){
		++cnt;
		return;
	}
	for(int i=0;i<v[st].size();i++){
		if(data[v[st][i]]==0){
			data[v[st][i]]=1;
			dfs(v[st][i],lv+1);
			data[v[st][i]]=0;
		}
	}
}
int main(){
	memset(data,0,sizeof data);
	data[1]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	printf("%d",cnt);
}
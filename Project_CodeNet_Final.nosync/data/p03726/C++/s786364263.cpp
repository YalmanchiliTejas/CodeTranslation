//by xiqiao
#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
vector <int> v[maxn];
int is[maxn],d[maxn];
int n;
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		v[x].push_back(y);v[y].push_back(x);
		d[x]++;d[y]++;

	}
	queue <int> q;
	for(int i=1;i<=n;i++){
		if(d[i]==1)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		if(is[x])continue;
		if(d[x]==1){
			int y;
			for(int i=0;i<(int)v[x].size();i++){
				if(!is[v[x][i]]){
					y=v[x][i];break;
				}
			}
			is[y]=1;is[x]=2;//cout<<y<<" "<<x<<endl;
			for(int i=0;i<(int)v[y].size();i++){
				d[v[y][i]]--;
				if(d[v[y][i]]==1){
					q.push(v[y][i]);
				}
			}
		}
	}
	int now=1;
	for(int i=1;i<=n;i++){
		if(is[i]==0){
			is[i]=now;
			if(now==1)now=2;else now=1;
		}
	}
	for(int i=1;i<=n;i++){
		int flag=1;
		if(is[i]==2)continue;
		for(int j=0;j<(int)v[i].size();j++){
			if(is[v[i][j]]==2){
				flag=0;break;
			}
		}
		if(flag){
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}
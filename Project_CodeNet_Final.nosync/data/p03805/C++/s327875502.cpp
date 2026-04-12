#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,walk[100],c[10],coun[10],re[10];
stack<int> stk;
vector<int> v[100];
void path(int x,int lv){
	re[0] = v[x].size();
	for(int i=0;i<v[x].size();i++){
		for(int j=0;j<lv;j++){
			if(walk[j] == v[x][i]){
				re[0]--;
				break;
			}
		}
	}
	//printf("%d %d %d\n",lv,re[0],v[x].size());
	if(re[0] > 0){
		for(int i=0;i<v[x].size();i++){
			c[0] = 0;
			for(int j=0;j<lv;j++){
				if(walk[j] == v[x][i]){
					c[0] = 1;
					break;
				}
			}
			if(c[0] == 0){
				walk[lv] = v[x][i];
				path(v[x][i],lv+1);
			}
		}
	}
	else{
		if(lv == n){
			coun[0]++;
		}
		return;
	}
}
int main(){
	memset(walk,0,sizeof walk);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	walk[0] = 1;
	path(1,1);
	printf("%d",coun[0]);
}
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+5;

int N;

vector<int> To[MaxN];

int Check(int u,int fa){
	int i,v,cnt=0;
	for(i=0;i<To[u].size();i++)
		if((v=To[u][i])^fa)
			cnt+=Check(v,u);
	return cnt^(cnt<2);
}

int main(){
	int i,u,v;
	scanf("%d",&N);
	for(i=1;i<N;i++){
		scanf("%d%d",&u,&v);
		To[u].push_back(v);
		To[v].push_back(u);
	}
	puts(Check(1,0)?"First":"Second");
	return 0;
}
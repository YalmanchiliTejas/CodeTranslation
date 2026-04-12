#include<bits/stdc++.h>
using namespace std;

int adj[30][30];
int gl=0,n,m;

int rec(int bmsk,int prev,int depth){
	if(depth==n && bmsk!=gl)
		return 0;
	if(bmsk==gl)
		return 1;
	int cnt=0;
//	cout<<bmsk<<" "<<prev<<" "<<depth<<endl;
	for(int i=1;i<=n;i++){
		int tmp=1<<i;
		int tmp2=tmp&bmsk;
		//cout<<tmp<<" sadfg "<<(tmp2)<<endl;
		if(tmp2==0 && adj[prev][i]){
		//	cout<<i<<" sdf "<<endl;
			cnt+=rec(bmsk|tmp,i,depth+1);
		}
	}
	return cnt;
}

int main(){
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		gl|=(1<<i);
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	cout<<rec(1<<1,1,1)<<endl;
	return 0;
}

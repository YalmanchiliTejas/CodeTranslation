#include<bits/stdc++.h>
using namespace std;
bool p[8][8];int n,m,a,b;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){cin>>a>>b;a--;b--;p[a][b]=true;p[b][a]=true;}
	int G[8]={0,1,2,3,4,5,6,7};
	int cnt=0;
	do{
		if(G[0]!=0)continue;
		bool OK=true;
		for(int i=1;i<n;i++){
			if(p[G[i-1]][G[i]]==false)OK=false;
		}
		if(OK==true)cnt++;
	}while(next_permutation(G,G+n));
	cout<<cnt<<endl;
	return 0;
}
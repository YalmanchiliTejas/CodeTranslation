#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N],vis[N],vv[N];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	char ch;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	cin>>ch;
	 	if(ch=='#') a[i][j]=1;
	 }
	for(int i=1;i<=n;++i){
		int flag=1;
		for(int j=1;j<=m;++j){
			if(a[i][j]){
				flag=0;break;
			}
		}
		if(flag) vis[i]=1;
	}
	for(int i=1;i<=m;++i){
		int flag=1;	
		for(int j=1;j<=n;++j)
			if(a[j][i]){
				flag=0;break;
			}	
		if(flag) vv[i]=1;
	}
	int ff=1,f=1;
	for(int i=1;i<=n;++i) if(!vis[i]) ff=0;
	for(int i=1;i<=m;++i) if(!vv[i]) f=0;
	if(ff&&f) return 0;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		for(int j=1;j<=m;++j){
			if(!vv[j]) {
				if(a[i][j]) cout<<"#";
				else cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char ch[105][105];
int n, m, x[105], y[105];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%s", (ch[i]+1));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]!='.'){
				x[i]=1;
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ch[j][i]!='.'){
				y[i]=1;
				continue;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i]==0) continue;
		for(int j=1;j<=m;j++) if(y[j]==1) printf("%c", ch[i][j]);
		cout<<endl;
	}
} 
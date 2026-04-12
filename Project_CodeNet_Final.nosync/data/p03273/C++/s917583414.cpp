#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[105][105];
int l[105],r[105];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for (int i=1;i<=n;i++){
		int t=0;
		for (int j=1;j<=m;j++){
			if(s[i][j]== '.'){
				t++;
			}
		}
		if(t==m) l[i]=1;
	}
	for (int i=1;i<=m;i++){
		int t=0;
		for (int j=1;j<=n;j++){
			if(s[j][i]=='.'){
				t++;
			}
		}
		if(t==n) r[i]=1;
	}
	for (int i=1;i<=n;i++){
		int flag=0;
		for (int j=1;j<=m;j++){
			if(l[i]||r[j]) continue;
			flag=1;
			printf("%c",s[i][j]);
		}
		if(flag) printf("\n");
	}
	return 0;
}
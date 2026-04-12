#include<cstdio>
#include<iostream>
using namespace std;
char a[100][100];
int main(){
int n,m;
cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			}
	}	
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.')
			tot++;
			if(tot==m){
				for(int k=1;k<=m;k++)
				a[i][k]='*';
			}
		}
	}
	for(int j=1;j<=m;j++){
		int ytot=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]=='.'||a[i][j]=='*')
			ytot++;
			if(ytot==n){
				for(int k=1;k<=n;k++)
				a[k][j]='*';
			}
		}
	}
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]!='*'){
				flag=1;
			printf("%c",a[i][j]);	
			}
		}
		if(!flag)
		continue;
		printf("\n");
	}
}
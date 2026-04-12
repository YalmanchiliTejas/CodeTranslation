#include<bits/stdc++.h>
using namespace std;
bool flg,s1[105][105];
int i,j;
char s[105][105];
int main(void)
{
	int n,m;
	
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>s[i]+1;	
	
	for(i=1;i<=n;i++){
		flg=1;
		for(j=1;j<=m;j++){
			if(s[i][j]=='#')
				flg=0;
		}	
		if(!flg) continue;
		for(j=1;j<=m;j++) {s1[i][j]=1;}		
	}
	
	for(i=1;i<=m;i++){
		flg=1;
		for(j=1;j<=n;j++){
			if(s[j][i]=='#')
				flg=0;
		}	
		if(!flg) continue;
		for(j=1;j<=n;j++) {s1[j][i]=1;}		
	}	
	
	for(i=1;i<=n;i++){
		 flg= 0;
		for(j=1;j<=m;j++){
			if(!s1[i][j]) cout<<s[i][j], flg= 1;
		}
		if(flg) cout<<endl;
	}
}	
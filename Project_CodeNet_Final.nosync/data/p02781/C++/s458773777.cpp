#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
int n,m;
ll f[105][4][10][2];
char ch[105];
int main(){
	scanf("%s",ch+1);n=strlen(ch+1);
	scanf("%d",&m);
	for(reg int i=1;i<ch[1]-'0';i++)f[1][1][i][0]=1;
	f[1][0][0][0]=f[1][1][ch[1]-'0'][1]=1;
	for(reg int i=1;i<n;i++){
		for(reg int j=0;j<=m;j++){
			for(reg int k=0;k<10;k++){
				if(f[i][j][k][0]){
					f[i+1][j][0][0]+=f[i][j][k][0];
					if(j<m){
						for(reg int l=1;l<10;l++)
							f[i+1][j+1][l][0]+=f[i][j][k][0];
					}
				}
				if((k==ch[i]-'0')&&f[i][j][k][1]){
					if(j+(ch[i+1]-'0'>0)<=m)
						f[i+1][j+(ch[i+1]-'0'>0)][ch[i+1]-'0'][1]+=f[i][j][k][1];
					if(ch[i+1]-'0'>0)f[i+1][j][0][0]+=f[i][j][k][1];
					if(j<m)for(reg int l=1;l<ch[i+1]-'0';l++)f[i+1][j+1][l][0]+=f[i][j][k][1];
				}
			}
		}
	}
	reg ll Ans=0;
	for(reg int i=0;i<10;i++)
		Ans+=f[n][m][i][0]+f[n][m][i][1];
	printf("%lld\n",Ans);
	return 0;
}
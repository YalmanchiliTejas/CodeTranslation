#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char k[10010];
int d,l,ans;
int g[10010][105];

int lmod(int r){
	if(r<0) r+=d;
	r%=d;
	return r;
}

void dfs(int t,int f){
	if(t>l){
		if(f==0) ans++,ans%=mod;
		return;
	}
	for(int i=0;i<k[t]-'0';i++){
		ans+=g[l-t][lmod(d-f-i)];
		ans%=mod;
	}
	dfs(t+1,(f+k[t]-'0')%d);
}

int main(){
	scanf("%s",k+1);
	scanf("%d",&d);
	l=strlen(k+1);
	g[0][0]=1;
	for(int i=0;i<=9;i++) g[1][i%d]++;
	for(int i=2;i<=10000;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<d;k++){
				g[i][(k+j)%d]+=g[i-1][k];
				g[i][(k+j)%d]%=mod;
			}
		}
	}
	dfs(1,0);
	if(ans<1) ans+=mod;
	cout<<ans-1<<endl;
	
	return 0;
}
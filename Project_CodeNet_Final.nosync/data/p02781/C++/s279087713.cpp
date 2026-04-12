#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
char c[110];
int a[110],w[5],sum[110],ans=0;
inline void check(){
	if(m==1){
		if(w[1]!=1)ans+=9;
		else ans+=a[1];
		return;
	}
	if(m==2){
		if(w[1]==1){
			if(sum[w[2]-1]-sum[w[1]]==0){
				ans+=(a[1]-1)*9+a[w[2]];
			}
			else ans+=a[1]*9;
		}
		else ans+=81;
		return;
	}
	if(m==3){
		if(w[1]==1){
			int now=0;
			ans+=(a[1]-1)*9*9;
			for(register int i=1;i<=9;i++){	
				if(sum[w[2]-1]-sum[w[1]]==0 && i>a[w[2]])continue;
				for(register int j=1;j<=9;j++){
					if(sum[w[2]-1]-sum[w[1]]==0 && sum[w[3]-1]-sum[w[2]]==0 && i==a[w[2]] && j>a[w[3]])continue;
					ans++;
				}
			}
		}
		else ans+=9*9*9;
	}
	return;
}

inline void dfs(int x,int now){
	if(x==m+1){check();return;}
	for(register int i=now;i<=n;i++){
		w[x]=i;
		dfs(x+1,i+1);
		w[x]=0;
	}
	return;
}
signed main(){
	scanf("%s",c+1);n=strlen(c+1);
	m=read();
	for(register int i=1;i<=n;i++){
		a[i]=c[i]-'0';
		sum[i]=sum[i-1]+a[i];
	}
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
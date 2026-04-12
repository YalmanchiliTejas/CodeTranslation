#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int mod = 998244353;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
int a[3010],num[3010];
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	/*for(register int l=1;l<=n;l++){
		for(register int i=1;i<=m;i++)num[i]=0;num[0]=1;
		for(register int r=l;r<=n;r++){	
			for(register int i=m;i>=a[r];i--){
				(num[i]+=num[i-a[r]])%=mod;
			}
			(ans+=num[m])%=mod;
		}
	}*/
	for(register int i=1;i<=n;i++){ 
		for(register int j=m;j>=a[i];j--){
			(num[j]+=num[j-a[i]])%=mod;
			//cerr<<i<<" "<<j<<": "<<f[j]<<endl;
		}
		(num[a[i]]+=i)%=mod;
		(ans+=num[m])%=mod;
	}
	printf("%d\n",ans);
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3000+999;
int n,ans,p,f[maxn],g[maxn][maxn],C[maxn][maxn];

int poww(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%p;b>>=1;a=a*a%p;
	}
	return ans;
}
signed main(){
	cin>>n>>p;
    for(int i=0;i<=n;++i){
        C[i][0]=g[i][0]=1;
        for(int j=1;j<=i;++j) 
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%p,
            g[i][j]=(g[i-1][j-1]+(j+1)*g[i-1][j]%p)%p;
    }
    for(int i=0;i<=n;++i){
        int tmp=poww(2,poww(2,n-i,p-1),p),num=poww(2,n-i,p),now=1,sum=0;
        for(int j=0;j<=i;++j)sum=(sum+g[i][j]*now%p)%p,now=now*num%p;
        ans=((ans+(((i&1)?p-C[n][i]:C[n][i])*tmp%p)*sum%p)%p+p)%p;
    }
	cout<<ans;
}
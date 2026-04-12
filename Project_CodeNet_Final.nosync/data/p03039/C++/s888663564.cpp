#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
#define mod 1000000007
using namespace std;
inline int read(){
	int f=1,ans=0;char c;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
int n,m,k,ans;
int Qsum(int a1,int an){
	if(a1>an) return 0;
	return ((a1+an)*(an-a1+1)/2)%mod;
}
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a,ans%=mod;
        a*=a,a%=mod;
        b>>=1;
    }
    return ans;
}
int C(int a,int b){
    int s1=1,s2=1;
    for(int i=a;i>=a-b+1;i--) s1*=i,s1%=mod;
    for(int i=b;i>=1;i--) s2*=i,s2%=mod;
    return ((s1%mod)*ksm(s2,mod-2)%mod)%mod;
}
int lucas(int a,int b){
    if(b==0) return 1;
    return (C(a%mod,b%mod)*lucas(a/mod,b/mod))%mod;
}
signed main(){
	n=read(),m=read(),k=read();
	int Num=lucas((n*m)-2,k-2)%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int G=0;
			G+=(((n-i+1)*Qsum(1,m-j))%mod)+((n-i)*Qsum(1,j-1))%mod;G%=mod;
			G+=m*Qsum(1,n-i);G%=mod; 
			ans+=(G*Num);ans%=mod; 
		}
	}printf("%lld\n",ans);
}

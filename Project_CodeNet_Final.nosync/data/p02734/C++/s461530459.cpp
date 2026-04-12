#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 3030
const ll mod=998244353;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],S;
ll dp[N],ans;
int main(){
	n=read(),S=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=S;j>a[i];--j){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		dp[a[i]]=(dp[a[i]]+i)%mod;
		ans=(ans+dp[S]*(n-i+1)%mod)%mod;
		dp[S]=0;
	}
	printf("%lld\n",ans);
	return 0;
}
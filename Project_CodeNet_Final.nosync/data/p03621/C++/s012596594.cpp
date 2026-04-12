#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct Combin{
	#define N 1000005
	int fac[N],rv[N],facrv[N];
	Combin(){
		fac[0]=rv[1]=facrv[0]=1;
		for(int i=2;i<N;i++) rv[i]=((-(mod/i)*1LL*rv[mod%i]%mod)+mod)%mod;
		for(int i=1;i<N;i++) fac[i]=1LL*fac[i-1]*i%mod;
		for(int i=1;i<N;i++) facrv[i]=1LL*facrv[i-1]*rv[i]%mod;
	}
	int C(int r1,int n1){
		if(r1>n1) return 0;
		return fac[n1]*1LL*facrv[r1]%mod*facrv[n1-r1]%mod;
	}
	#undef N
}C;
#define N 10004
char a[N],b[N];
int num[2],len;
int dp[N][N];
int main(){
    scanf("%s%s",a+1,b+1);
    len=strlen(a+1);
    for(int i=1;i<=len;i++)
        if(a[i]=='1') num[b[i]-'0']++;
    dp[0][0]=1;
    for(int i=1;i<=num[0];i++){
        dp[0][i]=dp[0][i-1]*1LL*i*i%mod;
        for(int j=1;j<=num[1];j++)
            dp[j][i]=(dp[j][i-1]*1LL*i*i+dp[j-1][i]*1LL*i*j)%mod;
    }

    long long ans=0;
    for(int i=0;i<=num[1];i++)
        ans+=C.fac[i]*1LL*C.fac[i]%mod*C.C(i,num[1])%mod*dp[num[1]-i][num[0]]%mod*C.C(i,num[0]+num[1])%mod;
    cout<<ans%mod<<endl;
    return 0;
}
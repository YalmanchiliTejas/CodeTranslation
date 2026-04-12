#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+6;
typedef long long ll;
const ll M=1000000007;
ll f[maxn],nf[maxn],inv[maxn],n,m,p[maxn],ans,dp[maxn][2][2],v[maxn],mx,l;
char s[maxn];
ll work_dp(int n){
    if (n==1) return 1;
    dp[1][0][0]=dp[1][1][1]=1;
    for (int i=2;i<=n;i++){
        for (int o=0;o<=1;o++){
            dp[i][o][0]=(dp[i-1][o][0]+dp[i-1][o][1])%M;
            dp[i][o][1]=dp[i-1][o][0];
        }
    }
    return (dp[n][0][0]+dp[n][0][1]+dp[n][1][0])%M;
}

int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-(M/i)*inv[M%i]%M;
    nf[0]=f[0]=p[0]=1; for (int i=1;i<maxn;i++) f[i]=f[i-1]*i%M,nf[i]=nf[i-1]*inv[i]%M,p[i]=p[i-1]*2%M;
    cin >> n >> l;
    scanf("%s",s+1);
    if (s[1]=='B'){
        for (int i=1;i<=l;i++) if (s[i]=='B') s[i]='R'; else s[i]='B';
    }
    for (int i=1;i<=l;i++) if (s[i]=='R') v[i]=v[i-1]+1; else v[i]=0;
    if (v[l]==l){
        cout << work_dp(n) << endl;
        return 0;
    }
    for (int i=1;i<l;i++) if (v[i]>0&&v[i+1]==0){
        if (mx==0) mx=v[i]/2*2+1;
        else if (v[i]%2==1) mx=min(mx,v[i]);
    }
    if (n%2==1){puts("0");return 0;}
    n/=2; m=(mx+1)/2;
    for (int i=0;i*(m+1)<=n&&n-i*m-1>=0;i++){
        int u=n-i*(m+1);
        if (i&1) (ans-=p[u]*f[n-i*m-1]%M*nf[i]%M*nf[u])%=M;
        else (ans+=p[u]*f[n-i*m-1]%M*nf[i]%M*nf[u])%=M;
    }
    ans=(ans*n-1)%M;
    cout << (ans+M)*2%M << endl;
}

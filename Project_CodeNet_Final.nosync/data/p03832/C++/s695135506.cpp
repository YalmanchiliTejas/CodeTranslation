
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

ll rui(ll a,ll b){
    if(b==1) return a%mod;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%mod;
    else return (rui(a,b-1)*a)%mod;
}

ll comb(ll a,ll b){
    ll ans=1;
    for(ll i=a;i>a-b;i--){
        ans=ans*i%mod;
    }
    for(ll i=1;i<=b;i++){
        ans=(ans*rui(i,mod-2))%mod;
    }
    return ans;
}

int main(){
    
    int N,A,B,C,D;cin>>N>>A>>B>>C>>D;
    ll dp[1001][1001],p[1001];//i人以下のみ合計はj
    
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=0;i<1001;i++){
        if(i) p[i]=p[i-1]*i%mod;
        else p[i]=1;
    }
    
    for(int i=0;i<A;i++){
        dp[i][0]=1;
    }
    
    for(int i=A;i<=B;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=C;k<=min(D,j/i);k++){
                if(j-k*i<0) continue;
                dp[i][j]+=dp[i-1][j-i*k]*p[N-(j-i*k)]%mod*rui(p[N-j]*rui(p[i],k)%mod*p[k]%mod,mod-2)%mod;
                dp[i][j]=dp[i][j]%mod;
            }
        }
    }
    
    cout<<dp[B][N]<<endl;
    
}


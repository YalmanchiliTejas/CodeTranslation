#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=2005,INF=1<<30;
ll dp[MAX];

void mul(int a){
    if(a<=0) return;
    for(int j=1;j<MAX;j++){
        dp[j]+=dp[j-1];
        if(dp[j]>=mod) dp[j]-=mod;
    }
    
    for(int j=MAX-1;j>=0;j--){
        if(j-(a+1)>=0){
            dp[j]-=dp[j-(a+1)];
            if(dp[j]<0) dp[j]+=mod;
        }
    }
}//1+x+x^2+...+x^aから選ぶ

void div(int a){
    for(int j=MAX-1;j>=1;j--){
        dp[j]-=dp[j-1];
        if(dp[j]<0) dp[j]+=mod;
    }
    
    for(int j=0;j<MAX;j++){
        if(j-(a+1)>=0){
            dp[j]+=dp[j-(a+1)];
            if(dp[j]>=mod) dp[j]-=mod;
        }
    }
}//逆

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll comb(ll a,ll b){
    ll res=1;
    for(ll i=0;i<b;i++){
        res*=(a-i)%mod;
        res%=mod;
        res*=rui(i+1,mod-2);
        res%=mod;
    }
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        ll N,D,X;cin>>N>>D>>X;
        if(N==0) break;
        X-=2;
        
        ll ans=0;
        
        for(ll i=1;i<=min(N,D);i++){
            mul(X);
            
            ans+=dp[N-i]*comb(D,i);
            
            ans%=mod;
        }
        if(X<0) ans=0;
        cout<<ans<<endl;
    }
}


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll mod = 1000000007;
string k;
int n,d;
ll dp[101][10050][2];

ll rec(int rem, int idx, int flag){
    
    if(idx == n){
        return rem==0?1:0;
    }
    if(dp[rem][idx][flag]!=-1)return dp[rem][idx][flag];
    int l=9,f;
    ll cnt=0;
    if(!flag)l=k[idx]-'0';
    for(int i=0;i<=l;i++){
        f=flag;
        if(i<k[idx]-'0')f=1;
        cnt=(cnt+rec((rem+i)%d,idx+1,f))%mod;
        
    }
    return dp[rem][idx][flag]=cnt;
}


int main(){
   memset(dp,-1,sizeof(dp));
   
   cin>>k>>d;
   n=k.length();
    ll ans=rec(0,0,0);
    ans+=mod-1;
    ans%=mod;
    cout<<ans;
    
    
    
    
    
    
    
    
    
    return 0;
}
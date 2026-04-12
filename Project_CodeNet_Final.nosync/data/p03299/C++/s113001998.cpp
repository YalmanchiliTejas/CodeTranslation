#include<bits/stdc++.h>
using namespace std;

long long n,h[105],dp[105],tmp,mod=1000*1000*1000+7,pre[105],l,r,omega,dest,prog;
deque<pair<long long,int> > v;

long long fastp(long long base,int exp){
    if(exp==0)return 1;
    
    long long val=fastp(base,exp/2);
    val=(val*val)%mod;
    if(exp%2)val*=base;
    return val%mod;
}


int main(){

	cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];

    dp[n+1]=1;
    pre[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]*fastp(2,max(0ll,h[i]-h[i-1]));
        pre[i]%=mod;
    }
    
    for(int i=n;i>0;i--){
        tmp=2*dp[i+1];
        
        v.clear();
        v.push_back({2,n+1});
        for(int j=n;j>=i;j--){
            while(v.size()>0 && v.back().first>=h[j]+1)v.pop_back();
            v.push_back({h[j]+1,j});
        }
        
        while(v.size()>1 && v[1].first<=h[i-1])v.pop_front();
        
        v[0].first=max(v[0].first,h[i-1]+1);
        
        for(int j=0;j<v.size()-1;j++){
            l=v[j].first;
            r=v[j+1].first-1;
            if(l>r)continue;
            dest=v[j].second;
            omega=(pre[dest-1]*fastp(pre[i],mod-2))%mod;
            prog=(fastp(2,h[i]-l)*(2-fastp(fastp(2,r-l),mod-2)))%mod;
            prog+=mod;
            prog%=mod;
            tmp+=((2ll*omega*prog)%mod*dp[dest])%mod;
            tmp%=mod;
        }
        
        dp[i]=tmp%mod;
    }
    
    cout<<(dp[1]%mod+mod)%mod<<endl;

return 0;
}

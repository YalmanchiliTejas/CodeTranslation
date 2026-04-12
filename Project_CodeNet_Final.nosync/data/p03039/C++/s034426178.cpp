#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

ll rui(ll u,ll t){
    if(t==0) return 1;
    else if(t==1) return u;
    else if(t%2==0) return ((rui(u,t/2))*(rui(u,t/2)))%mod;
    else return (rui(u,t-1)*u)%mod;
}

ll comb(ll a,ll b){
    ll ans=1;
    for(ll i=a;i>a-b;i--){
        ans*=i;
        ans=ans%mod;
    }
    for(ll i=1;i<=b;i++){
        ans*=rui(i,mod-2);
        ans=ans%mod;
    }
  ans*=rui(2,mod-2);
  ans=ans%mod;
    return ans;
}

int main(){
    
    ll N,M,K;cin>>N>>M>>K;
    ll sum1=0,sum2=0,sum;
    for(ll i=1;i<M;i++){
        sum1+=(M-i)*2*i;
        sum1=sum1%mod;
    }
    for(ll i=1;i<N;i++){
        sum2+=(N-i)*2*i;
        sum2=sum2%mod;
    }
    sum=((sum1*N*N)%mod+(sum2*M*M)%mod)%mod;
    
    sum*=comb(N*M-2,K-2);
    sum=sum%mod;
    
    cout<<sum<<endl;
}


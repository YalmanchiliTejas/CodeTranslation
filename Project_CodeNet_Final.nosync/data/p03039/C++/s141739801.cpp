#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
ll mod=pow(10,9)+7;
struct Combination{
    vec n,n_rev;

    Combination(int N){
        n.resize(N+1);
        n_rev.resize(N+1);
        n[0]=1;n_rev[1]=1;
        for(int i=1;i<=N;i++){
            n[i]=((ll)i*n[i-1])%mod;
        }
        for(int i=2;i<=N;i++){
            n_rev[i]=matpow(n[i],mod-2);
        }
    }

    //累乗(aのk乗)
    ll matpow(ll a,int k){
        ll dp=1,mt=a;
        while(k>0){
            if(k & 1)dp=(dp*mt)%mod;
            mt=(mt*mt)%mod;
            k/=2;
        }
        return dp;
    }

    ll comb(int N,int r){  
        if(r==0 || N==r)return 1;
        return (((n[N]*n_rev[r])%mod)*n_rev[N-r])%mod;
    }
};

int main(){
    ll N,M,K;cin>>N>>M>>K;
    Combination Comb(N*M);
    ll ans=0;
    for(int y=1;y<N;y++){
        ans=(ans+(ll)y*(N-y)*M*M)%mod;
    }
    for(int x=1;x<M;x++){
        ans=(ans+(ll)x*(M-x)*N*N)%mod;
    }
    ans=(ans*Comb.comb(N*M-2,K-2))%mod;
    cout<<ans<<endl;
    return 0;
}
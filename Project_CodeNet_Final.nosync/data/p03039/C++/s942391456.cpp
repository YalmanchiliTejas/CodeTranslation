#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const int mod=1e9+7;
const int sz=200005;

int fact[sz],inv[sz],ifact[sz];

void make(){
    fact[0]=fact[1]=inv[1]=ifact[0]=ifact[1]=1;
    for(int i=2;i<sz;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
    }
}

int comb(int n,int k){
    if(n<k) return 0;
    return fact[n]*ifact[k]%mod*ifact[n-k]%mod;
}

void add(int &a,int b)
{
    a=(a+b)%mod;
}

signed main()
{
    make();

    int N,M,K; cin>>N>>M>>K;
    int ans=0;
    for(int d=1;d<N;d++){
        int tmp=d*(N-d)%mod*M%mod*M%mod*comb(N*M-2,K-2)%mod;
        add(ans,tmp);
    }
    for(int d=1;d<M;d++){
        int tmp=d*(M-d)%mod*N%mod*N%mod*comb(N*M-2,K-2)%mod;
        add(ans,tmp);
    }
    cout<<ans<<endl;
}
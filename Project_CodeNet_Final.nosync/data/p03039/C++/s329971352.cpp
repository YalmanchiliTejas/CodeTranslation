#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)

array<ll,2> inv(ll a,ll m){
    array<ll,2> val;
    a=a%m;
    if(a==1){
        val[0]=1;
        val[1]=0;
    }else{
        array<ll,2> hoge;
        ll k=m/a,mm=m%a;
        hoge=inv(mm,a);
        val[1]=hoge[0]-k*a;
        val[0]=hoge[1]-k*hoge[0]+k*m;
    }
    if(val[0]>m-1){
        ll n=val[0]/m;
        val[0]=val[0]%m;
        val[1]=val[1]+n*a;
    }
    return val;
}

ll comb(ll a,ll b,ll m){
    if(b==0) return 1;
    if(b==1) return a%m;
    return ((((a%m)*inv(b,m)[0])%m)*comb(a-1,b-1,m))%m;
}


int main(){
    ll N,M,K;
    cin>>N>>M>>K;
    ll ans=0;
    ll hoge=comb(N*M-2,K-2,mod);
    ll MM=(M*M)%mod;
    ll NN=(N*N)%mod;
    Rep(d,N-1){
        ans=(ans+(N-d)*(MM*hoge)%mod*d)%mod;
    }
    Rep(d,M-1){
        ans=(ans+(M-d)*(NN*hoge)%mod*d)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
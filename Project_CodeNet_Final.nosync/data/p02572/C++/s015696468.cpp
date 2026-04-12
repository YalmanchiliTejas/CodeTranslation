//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,ans=0,sum=0; cin>>n;
    rep(i,n){
        ll a; cin>>a;
        ans=(ans+a)%MOD;
        sum=(sum+a*a)%MOD;
    }
    ans=ans*ans%MOD;
    ans=(ans-sum+MOD)%MOD*(MOD+1)/2%MOD;
    cout<<(ans+MOD)%MOD<<endl;
}
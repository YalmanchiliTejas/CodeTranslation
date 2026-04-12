#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    vector<int>A(N);
    vector<ll>s(N);
    ll ans=0;
    rep(i,N){
        cin>>A.at(i);
        if(i==0){
            s.at(i)=A.at(i);
        }else{
            s.at(i)+=s.at(i-1)+A.at(i);
        }
    }
    rep(i,N){
        ll sum=(s.at(N-1)-s.at(i))%mod;
        ans+=A.at(i)*sum;
        ans%=mod;
    }
    cout<<ans<<endl;



}

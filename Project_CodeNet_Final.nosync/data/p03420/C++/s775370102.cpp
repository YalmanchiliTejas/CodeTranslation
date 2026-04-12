#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,k,ans=0;
    cin>>n>>k;
    rep(i,n){
        ll a=i+1;
        if(a<=k) continue;
        else ans+=n/a*(a-k)+(n%a-k+1)*(n%a-k+1>0);
    }
    cout<<ans*(k>0)+n*n*(!k);
}
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
using ll=long long;
using namespace std;
ll a[220000],x[220000],y[220000];
int main(){
    ll n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)x[i]=(i>1?x[i-2]:0)+a[i];
    rep(i,1,n){
        if(i%2==0)y[i]=max(y[i-1],(i>2?y[i-2]:0)+a[i]);
        else y[i]=max(x[i-1],(i>2?y[i-2]:0)+a[i]);
    }
    cout<<y[n-1];
}
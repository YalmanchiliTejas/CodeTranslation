#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll n;
  ll x,m;
  cin>>n>>x>>m;
  ll a[m+1];
  a[0]=x;
  rep(i,0,m){
    a[i+1]=a[i]*a[i]%m;
  }
  if(n<m){
    ll ans=0;
    rep(i,0,n){
      ans+=a[i];
    }
    cout<<ans<<endl;
  }
  else{
    int j=m-1;
    while(a[m]!=a[j]){
      j--;
    }
    ll ans=0;
    rep(i,0,j){
      ans+=a[i];
    }
    ll sum[m-j+1];
    sum[0]=0;
    rep(i,0,m-j){
      sum[i+1]=sum[i]+a[j+i];
    }
    ans+=(n-j)/(m-j)*sum[m-j]+sum[(n-j)%(m-j)];
    cout<<ans<<endl;
  }
}
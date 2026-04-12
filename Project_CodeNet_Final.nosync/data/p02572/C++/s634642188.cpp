#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
const ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  ll b[n+1];
  b[0]=0;
  rep(i,0,n){
    b[i+1]=b[i]+a[i];
    b[i+1]%=mod;
  }
  ll sum=0;
  rep(i,0,n-1){
    ll c=b[n]-b[i+1];
    if(c<0) c+=mod;
    sum+=a[i]*c%mod;
    sum%=mod;
  }
  cout<<sum<<endl;
}
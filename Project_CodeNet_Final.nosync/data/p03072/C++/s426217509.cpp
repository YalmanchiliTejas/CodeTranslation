#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;


int main(){
  int n,h[100];
  int mx=0;
  int ans=0;
  cin>>n;
  rep(i,n){
    cin>>h[i];
    mx=max(mx,h[i]);
    if(mx==h[i]) ans++;
  }
  cout<<ans<<endl;
  

  return 0;
}








#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;


int main(){
  int n;
  int a[100];
  int ans=BIG;
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }
  repi(i,1,n){
    a[i]+=a[i-1];
  }
  rep(i,n){
    ans=min(ans,a[i]/(i+1) );
  }
  cout<<ans<<endl;

  return 0;
}





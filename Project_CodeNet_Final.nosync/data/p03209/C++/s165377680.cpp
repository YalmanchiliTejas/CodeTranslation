#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n,X;
  cin>>n>>X;
  ll p[n+1]={};
  ll b[n+1]={};
  ll w[n+1]={};
  p[0]=1;
  w[0]=1;
  for(int i=1;i<=n;i++){
    p[i]=p[i-1]*2+1;
    b[i]=b[i-1]*2+2;
    w[i]=p[i]+b[i];
    //cout<<i<<" "<<p[i]<<" "<<b[i]<<endl;
  }

  ll ans=0;
  ll sum=0;
  ll x=X;
  for(int i=n;i>=0;i--){
    //cout<<i<<" "<<w[i]<<" "<<x<<" "<<ans<<endl;
    if(x==w[i]-1){
      ans=ans+p[i];
      break;
    }else if(x==w[i]){
      ans=ans+p[i];
      break;
    }else if(x==w[i]+1){
      ans=ans+p[i]+1;
      break;
    }else if(w[i]<x){
      x=x-w[i]-1;
      ans=ans+p[i]+1;
      i++;
    }else if(x<w[i]){
      x--;
    }

    if(x<=0) break;
  }

  cout<<ans<<endl;


  return 0;
}

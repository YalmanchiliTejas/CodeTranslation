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
  int n;
  cin>>n;
  ll a[n+1]={};
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  ll ans=0;
  while(1){
    ll ma=0;
    int mat=0;
    for(int i=0;i<n;i++){
      if(ma<a[i]) mat=i;
      ma=max(ma,a[i]);
    }
    if(ma<n) break;

    ll z=ma/n;
    for(int i=0;i<n;i++){
      if(i==mat) a[i]=a[i]%n;
      else a[i]+=z;
    }
    ans+=z;
  }

  cout<<ans<<endl;

  return 0;
}

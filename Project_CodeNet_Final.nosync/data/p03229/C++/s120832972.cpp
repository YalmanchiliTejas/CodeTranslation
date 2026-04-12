#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define INF 0x7FFFFFFF
#define ll long long
const double EPS = 1e-10;


int main(){
  ll n;
  ll ans=0;
  cin>>n;
  vector<ll> a(n,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  ll x,y;
  x=a[n-1];
  y=a[n-1];
  a.pop_back();
  ll p,q;
  p=0;
  q=a.size()-1;
  while(p!=q){
    if(max(abs(x-a[p]),abs(y-a[p]))>=max(abs(x-a[q]),abs(y-a[q]))){
      if(abs(x-a[p])>=abs(y-a[p])){
        ans+=abs(x-a[p]);
        x=a[p];
      }
      else{
        ans+=abs(y-a[p]);
        y=a[p];
      }
      p++;
    }
    else{
      if(abs(x-a[q])>=abs(y-a[q])){
        ans+=abs(x-a[q]);
        x=a[q];
      }
      else{
        ans+=abs(y-a[q]);
        y=a[q];
      }
      q--;
    }
  }
  ans+=max(abs(x-a[q]),abs(y-a[q]));
  cout<<ans<<endl;
}

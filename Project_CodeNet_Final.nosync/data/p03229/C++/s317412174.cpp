#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  int k=n/2;
  ll ans=0;
  if(n%2==0){
    for(int i=0;i<k-1;i++){
      ans-=a[i]*2;
    }
    ans-=a[k-1];
    ans+=a[k];
    for(int i=k+1;i<n;i++){
      ans+=a[i]*2;
    }
  }
  else{
    ll x=0,y=0;
    for(int i=0;i<k-1;i++){
      x-=a[i]*2;
      y-=a[i]*2;
    }
    x-=a[k-1],y-=a[k-1]*2;
    x-=a[k],y+=a[k];
    x+=a[k+1]*2,y+=a[k+1];
    for(int i=k+2;i<n;i++){
      x+=a[i]*2;
      y+=a[i]*2;
    }
    ans=max(x,y);
  }
  cout << ans << endl;
}
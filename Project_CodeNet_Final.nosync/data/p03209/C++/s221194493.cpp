#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long

ll n,x,ans;
vector<ll> l,ln;
void zzz(ll i){
  ll j=i;
  for(;i>0;i--){
    if(ln[i]+(j+1-i)==x){
      x=0;
      ans+=l[i];
      return;
    }
    if(ln[i]+(j+1-i)+1==x){
      x=0;
      ans+=l[i]+1;
      return;
    }
    if(ln[i]+(j+1-i)<x)break;
  }
  if(i>0){
    ans+=l[i]+1;
    x-=ln[i]+(j+1-i)+1;
    if(x>0)zzz(i-1);
  }
  else{
    x-=j+1;
    if(x>=3) ans+=3;
    else if(x>0) ans+=x;
  }

}

int main(){
  cin>>n>>x;
  ans=0;
  l.assign(n+1,0);
  ln.assign(n+1,0);
  l[0]++;
  ln[0]++;
  for(int j=1;j<=n;j++){
    l[j]=l[j-1]*2+1;
    ln[j]=ln[j-1]*2+3;
  }
  zzz(n-1);
  cout<<ans<<endl;
}

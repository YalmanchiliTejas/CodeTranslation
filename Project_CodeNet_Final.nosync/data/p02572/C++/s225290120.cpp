#include <bits/stdc++.h>
using namespace std;

int main() {
  using ll =long long ;
  ll a;
  cin>>a;
  ll b=0;
  ll c=0;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    vec.at(i)=vec.at(i)%1000000007;
    b+=vec.at(i);
    b=b%1000000007;
    c+=vec.at(i)*vec.at(i);
    c=c%1000000007;
  }
  ll e=b*b-c;
  for(ll i=0;e<0;i++){
    e+=1000000007;
  }
  if(e%2!=0){
    e+=1000000007;
  }
  ll f=e/2;
  ll g=f%1000000007;
  
  
  cout<<g<<endl;
    
    
}
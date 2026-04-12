#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b,c;
  cin>>b>>c;
  ll g=b;
  ll h=-1;
  
  if(a==1||b==0){
    cout<<g<<endl;
    return 0;
  }
  for(ll i=0;i<min(a,c)-1;i++){
    b=b*b%c;
    
    if(b==0){
      cout<<g<<endl;
      return 0;
    }
    if(b==1){
      cout<<g+a-1-i<<endl;
      return 0;
    }
    g+=b;
  }
  if(a<=c){
    cout<<g<<endl;
    return 0;
  }
  g-=b;
  ll k=b;
  vector<ll>vec(1,b);
  for(ll i=0;i<c;i++){
    b=b*b%c;
    if(b==vec.at(0)){
      h=i+1;
      break;
      
    }
    else{
      k+=b;
      vec.push_back(b);
    }
  }
  ll x=(a-c+1)%h;
  ll y=(a-c+1)/h;
  ll z=0;
  
  if(x!=0){
    for(ll i=0;i<x;i++){
      z+=vec.at(i);
    }
  }
  cout<<g+y*k+z<<endl;
  return 0;
}
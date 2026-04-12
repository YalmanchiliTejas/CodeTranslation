#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=1;
  ll c;
  cin>>c;
  for(ll i=0;i<a-1;i++){
    ll d;
    cin>>d;
    if(d>=c){
      b+=1;
      c=d;
    }
  }
  cout<<b<<endl;
  
  return 0;
  
}

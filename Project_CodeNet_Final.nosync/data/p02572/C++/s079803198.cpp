#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  ll c=0;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    vec.at(i)=vec.at(i)%1000000007;
    b+=vec.at(i);
  }
  b=b%1000000007+1000000007;
  vector<ll>vo(a);
  for(ll i=0;i<a;i++){
    vo.at(i)=(b-vec.at(i))%1000000007;
    b=vo.at(i)+1000000007;
  }
  for(ll i=0;i<a;i++){
    c+=vo.at(i)*vec.at(i)%1000000007;
    c=c%1000000007;
  }
  cout<<c<<endl;   
}

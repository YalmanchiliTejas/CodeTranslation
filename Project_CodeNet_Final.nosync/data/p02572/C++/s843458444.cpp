#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(int i=0; i<n; i++){
    cin>>A.at(i);
  }
  ll ans=0;
  ll x=0;
  for(int i=0; i<n; i++){
    ans=(ans+A.at(i)*x)%1000000007;
    x=(x+A.at(i))%1000000007;
  }
  cout<<ans<<endl;
}
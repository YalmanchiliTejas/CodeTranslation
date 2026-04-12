#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  ll ans=0;
  ll max=0;
  for(ll i=0;i<N;i++) {
ll H;
    cin>>H;
    if(H>=max) {
ans++;
      max=H;
    }
  }
  
  
  cout<<ans<<endl;
}
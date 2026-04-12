#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  string n;
  ll k;
  cin>>n>>k;
  if(n.size()<k){
    cout<<0<<endl;
    return 0;
  }
  ll ans=0;
  for(ll i=1;i<n.size();i++){
    if(i<k) continue;
    else {
      if(k==1) ans+=9;
      else if(k==2) ans+=81*(i-1);
      else ans+=729*(i-1)*(i-2)/2;
    }
  }
  if(k==1) ans+=(n.at(0)-'0');
  if(k==2) {
    ans+=(n.at(0)-'0'-1)*9*(n.size()-1);
    for(int i=1; i<n.size();i++){
      if(n.at(i)=='0') continue;
      else{
        ans+=(n.at(i)-'0');
        ans+=9*(n.size()-1-i);
        break;
      }
    }
  }
  if(k==3){
    ans+=(n.at(0)-'0'-1)*81*(n.size()-1)*(n.size()-2)/2;
    for(int i=1; i<n.size()-1;i++){
      if(n.at(i)=='0') continue;
      else{
        ans+=(n.at(i)-'0'-1)*9*(n.size()-i-1)+81*(n.size()-i-1)*(n.size()-i-2)/2;
        for(int j=i+1;j<n.size();j++){
          if(n.at(j)=='0') continue;
          else {
            ans+=(n.at(j)-'0');
            ans+=9*(n.size()-1-j);
            break;
          }
        }
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
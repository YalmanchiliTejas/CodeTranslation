#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include <numeric>
 
using namespace std;
typedef long long ll;
 
int main(){
ll n;
  cin>>n;
  ll h[n];
  for(ll i=0;i<n;i++){
  cin>>h[i];
  }
  ll count=1;
    for(ll i=1;i<n;i++){
      ll flag=1;
      for(ll j=0;j<i;j++){
      if(h[i]-h[j]<0)
        flag=0;
      }
      if(flag==1){
        count++;
      }
  
  }
  cout<<count;
  return 0;
 
}
 
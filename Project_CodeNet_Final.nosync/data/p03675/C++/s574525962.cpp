#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define pb push_back
using namespace std;

int main(void){
  int i,n;
  vector<int> res;
  int t;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>t;
    if(i%2){
      res.pb(t);
    }
    else{
      res.insert(res.begin(),t);
    }
  }
  if(n%2==0){
    for(i=n-1;i>=0;i--){
      i==0?cout<<res[i]<<endl:cout<<res[i]<<" ";
    }
  }
  else{
    for(i=0;i<n;i++){
      i==n-1?cout<<res[i]<<endl:cout<<res[i]<<" ";
    }
  }
  return 0;
}
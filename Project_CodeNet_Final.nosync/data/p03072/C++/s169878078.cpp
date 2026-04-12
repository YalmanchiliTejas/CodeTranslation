#include <bits/stdc++.h>
using namespace std;


int main(){
  int n; cin>>n;
  int ans=0;
  vector<int> vec(n);
  
  for(int i=0;i<n;i++){
    int count=0;
    cin>>vec[i];
      for(int j=0;j<i;j++){
        if(i!=0&&vec[i]>=vec[j])count++;
      }												
    if(count==i)ans++;
  }							
   cout<<ans<<endl;
}
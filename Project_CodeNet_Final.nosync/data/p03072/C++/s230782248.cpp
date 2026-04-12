#include<bits/stdc++.h>
using namespace std;
int a[45];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int sum=0;
  int ans=0;
  for(int i=0;i<n;i++){
    sum=0;
    for(int j=0;j<i;j++){
      if(a[i]<a[j]){
        sum++;
      }
    }
    if(sum==0){
      ans++;
    }
  }
  cout<<ans<<endl;
}
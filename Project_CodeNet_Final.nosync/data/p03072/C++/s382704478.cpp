#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,i,j;
  cin>>n;
  int h[n];
  for(i=0;i<n;i++)cin>>h[i];
  int cnt=n;
  for(i=1;i<n;i++){
    for(j=0;j<i;j++){
      if(h[i]<h[j]){
        cnt--;
        break;
      }
    }
  }
  cout<<cnt;
}
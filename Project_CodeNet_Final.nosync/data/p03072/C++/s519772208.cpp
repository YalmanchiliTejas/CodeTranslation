#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int h[109];
  cin>>n;
  int cnt=0;
  for(int i=0;i<n;i++)cin>>h[i];
  for(int i=0;i<n;i++){
    bool f=0;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]){
	f=1;
      }
    }
    if(f==0)cnt++;
  }
  cout<<cnt<<endl;
  return(0);
}

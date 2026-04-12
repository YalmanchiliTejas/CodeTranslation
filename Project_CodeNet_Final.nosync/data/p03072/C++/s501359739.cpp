#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=1;cin>>n;
  vector<int>h(n);
  for(int i=0;i<n;i++)cin>>h.at(i);
  if(n!=1){
    for(int i=1;i<n;i++){
      int c=0;
      for(int j=0;j<i;j++){
        if(h.at(j)>h.at(i))c++;
      }
      if(c==0)a++;
    }
  }
  cout<<a<<endl;
}
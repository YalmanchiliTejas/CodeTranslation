#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int w=h[0],aw=1;
  for(int i=1;i<n;i++){
    w=max(w,h[i]);
    if(w==h[i]){
      aw++;
    }
  }
  cout<<aw<<endl;
}

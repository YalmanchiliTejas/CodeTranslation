#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  int cnt=0;
  int mx=0,cp;
  for(int i=0;i<N;i++){
    cin>>cp;
    if(cp>=mx){
      mx=cp; cnt++;
    }
  }
  cout<<cnt<<endl;
}
#include  <bits/stdc++.h>
using namespace std;
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
int main(){
  string s;
  cin>>s;
  int acount=0,bcount=0;
  
  for(auto x:s){
    if(x=='A'){
      acount++;
    }
    else 
      bcount++;
  }
  if(acount>0&&bcount>0){
    cout<<"Yes"<<"\n";  
  }
  else{
    cout<<"No"<<"\n";  
  }
  return 0;
}
#include<iostream>
#include<string>
using namespace std;

string ll = "qwertasdfgzxcvb";

bool is_ll(char c){
  for(int i=0;i<ll.size();i++){
    if(ll[i]==c)return true;
  }
  return false;
}

int solve(string s){
  bool j = is_ll(s[0]);
  int ans = 0;
  for(int i=1;i<s.size();i++){
    bool jj = is_ll(s[i]);
    if(j!=jj){
      j = jj;
      ans ++;
    }
  }
  return ans;
}

int main(){
  string s;
  while(cin>>s,s!="#"){
    cout<<solve(s)<<endl;
  }
}
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  string s;
  cin>>s;
  for(i=1;i<s.size();i++){
    if(s[i-1]=='A' && s[i]=='C'){
      cout<<"Yes";
      return 0;
    }
  }
  cout<<"No";
}
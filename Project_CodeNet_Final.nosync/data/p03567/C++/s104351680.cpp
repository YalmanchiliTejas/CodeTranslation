#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  rep(i, s.size()-1){
    if(s[i]=='A' && s[i+1]=='C'){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
  return 0;
}
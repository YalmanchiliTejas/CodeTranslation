#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int main(){
  fast;
  string s;
  cin>>s;
  bool a0=0,b0=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      a0 = 1;
    }else{
      b0=1;
    }
  }
  cout<<(b0 && a0 ? "Yes\n":"No\n");
  return 0;
}

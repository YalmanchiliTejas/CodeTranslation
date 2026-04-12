#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main(){
  string s;
  cin>>s;
  bool ans=false;
  int l=s.size()-1;
  rep(i,l){
    if(s[i]=='A' && s[i+1]=='C'){
      ans=true;
      break;
    }
  }
  cout<<(ans?"Yes":"No")<<endl;
}
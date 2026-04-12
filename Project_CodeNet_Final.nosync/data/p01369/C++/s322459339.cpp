//koukyoukoukokukikoku
#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

bool right(char c){
  char a[11]={'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
  rep(i,11){
    if(c==a[i])return true;
  }
  return false;
}
int main(){
  while(true){
    string s;
    cin>>s;
    if(s=="#")break;
    bool flag=right(s[0]);
    int cn=0;
    for(int i=1; i<s.length(); i++){
      if(flag!=right(s[i])){flag=right(s[i]); cn++;}
    }
    cout<<cn<<endl;
  }
  return 0;
}
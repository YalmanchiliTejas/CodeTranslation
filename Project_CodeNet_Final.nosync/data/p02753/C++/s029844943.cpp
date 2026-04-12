#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int isA = 0, isB = 0;
  for(char c : s){
    if(c=='A') isA = 1;
    if(c=='B') isB = 1;
   }
  if(isA && isB) cout<<"Yes";
  else cout<<"No";
  return 0;
}
       

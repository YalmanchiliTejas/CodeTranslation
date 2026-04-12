#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  string s;cin>>s;
  bool f=0;
  if(s.at(0)!=s.at(1)) f=1;
  if(s.at(1)!=s.at(2)) f=1;  

  cout<<(f?"Yes":"No");
}
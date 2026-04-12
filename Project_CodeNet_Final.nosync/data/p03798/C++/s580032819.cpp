#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  s+=s.at(0);
  vector<string> m={"SS","SW","WS","WW"};
  for(int x=0;x<4;x++)
    for(int i=2;i<=n+1;i++)
      m.at(x)+=((m.at(x).at(i-2)=='S')^(m.at(x).at(i-1)=='S')^(s.at(i-1)=='o')?'S':'W');
  for(int x=0;x<4;x++){
    if(m.at(x).at(0)==m.at(x).at(n)&&m.at(x).at(1)==m.at(x).at(n+1)){
      cout<<m.at(x).substr(0,n)<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
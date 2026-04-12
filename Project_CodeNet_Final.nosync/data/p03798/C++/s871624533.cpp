#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;string s;cin>>n>>s;
  s+=s[0];vector<string> m={"SS","SW","WS","WW"};
  for(int x=0;x<4;x++)
    for(int i=2;i<=n+1;i++)
      m[x]+=((m[x][i-2]=='S')^(m[x][i-1]=='S')^(s[i-1]=='o')?'S':'W');
  for(int x=0;x<4;x++){
    if(m[x][0]==m[x][n]&&m[x][1]==m[x][n+1]){
      cout<<m[x].substr(0,n)<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
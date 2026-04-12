#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int q1=0,q2=0;
  for(int i=0;i<3;i++){
    if(s[i]=='A')
      q1+=1;
    if(s[i]=='B')
       q2+=1;
  }
  if(q1>0 && q2>0) 
     cout<<"Yes";
  else
     cout<<"No";
}

#include<bits/stdc++.h>
using namespace std;

int main(){

  int a=0,b=0;
  string s;
  cin>>s;
  for(int i=0;i<3;i++){

    if(s.at(i)=='A') a++;
    if(s.at(i)=='B') b++;

  }

  if(a>0&&b>0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;



  return 0;
}
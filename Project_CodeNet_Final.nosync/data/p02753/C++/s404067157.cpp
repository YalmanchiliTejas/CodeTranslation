#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s.at(0)=='A' && s.at(1)=='A' && s.at(2)=='A'){
    cout<<"No"<<endl;
  }
  else if(s.at(0)=='B' && s.at(1)=='B' && s.at(2)=='B'){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
  return 0;
}
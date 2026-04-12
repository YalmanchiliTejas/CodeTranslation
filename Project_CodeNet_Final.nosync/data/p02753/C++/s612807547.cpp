#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s.at(0)=='B'&&s.at(1)=='B'&&s.at(2)=='B'){
    cout<<"No"<<endl;
    return 0;
  }
  else if(s.at(0)=='A'&&s.at(1)=='A'&&s.at(2)=='A'){
    cout<<"No"<<endl;
    return 0;
  }
  else{
    cout<<"Yes"<<endl;
    return 0;
  }
}
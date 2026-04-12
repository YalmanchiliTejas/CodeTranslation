#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  bool flag = false;
  cin>>s;
  if(s.at(0)!=s.at(1)||s.at(1)!=s.at(2)||s.at(0)!=s.at(2))
     flag = true;
  if(flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}

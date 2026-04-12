#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans=true;
  if(s=="AAA"||s=="BBB"){
    ans=false;
  }
  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
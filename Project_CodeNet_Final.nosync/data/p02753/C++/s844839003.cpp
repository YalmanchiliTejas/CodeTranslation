#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >>s;
  
  string s1=s.substr(0,1), s2=s.substr(1,1), s3=s.substr(2,1);
  
  //cout <<s1<<s2<<s3;
  
  string ans;
  if (s1 ==s2 && s2==s3){
    ans ="No";
  }else{
    ans="Yes";
  }
  cout <<ans <<endl;
}

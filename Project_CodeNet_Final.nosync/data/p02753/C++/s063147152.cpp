#include <bits/stdc++.h>
using namespace std;
int main(){
  char s[3];
  char t[0];
  while(cin>>s){
    if(s[0]!=s[1]||s[1]!=s[2]){
      cout << "Yes" << "\n";
    }else{
      cout << "No" << "\n";
    }
  }
}
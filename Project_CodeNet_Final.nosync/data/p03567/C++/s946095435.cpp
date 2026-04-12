#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;bool ans = false;cin >> s;
  for(int i = 0;i<s.size()-1;i++){
    if (s.substr(i,2) == "AC") ans = true;
  }
  cout << ((ans) ? "Yes":"No") << endl;
}
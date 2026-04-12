#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;
  string ans = "aeiou";
  if(ans.find(c) == std::string::npos){
    cout << "consonant" << endl;
  }else{
    cout << "vowel" << endl;
  }
}
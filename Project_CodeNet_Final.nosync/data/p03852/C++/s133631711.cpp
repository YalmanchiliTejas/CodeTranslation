#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s, result="consonant";
  cin>>s;
  
  if(s=="a"|s=="i"|s=="u"|s=="e"|s=="o"){
    result="vowel";
  }
  
  cout << result << endl;
}
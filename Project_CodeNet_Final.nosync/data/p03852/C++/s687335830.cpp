#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  s = (s=="a" or s=="e" or s=="i" or s=="o" or s=="u") ? "vowel" : "consonant";
  cout << s << endl;
}

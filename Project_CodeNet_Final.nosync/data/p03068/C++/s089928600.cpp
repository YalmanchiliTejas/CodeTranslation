#include <iostream>
#include <string>

using namespace std;
int main() {
  int n, k;
  string s, c;
  cin >> n >> s >> k;
  
  c = s[k-1];
  for (int i=0; i<s.length(); i++) {
    if(s[i]!=c[0]) s[i]='*';
  }
  
  cout << s << endl;
}
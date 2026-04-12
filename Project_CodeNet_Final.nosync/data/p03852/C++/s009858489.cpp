#include "bits/stdc++.h"
using namespace std;
int main(void){
  string ans;
  char s[1];
  cin >> s;
  if (s[0]=='a'||s[0]=='i'||s[0]=='u'||s[0]=='e'||s[0]=='o')
    ans = "vowel";
  else
    ans = "consonant";
  cout << ans << endl;
}
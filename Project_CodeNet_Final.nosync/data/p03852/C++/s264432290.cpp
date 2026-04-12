#include <iostream>
using namespace std;

int main() {
string s;
cin >> s;
if(s[0]=='a' || s[0]=='i' ||s[0]=='u' ||s[0]=='e' ||s[0]=='o'){
  cout << "vowel"; return 0;
}
cout << "consonant";
return 0;
}
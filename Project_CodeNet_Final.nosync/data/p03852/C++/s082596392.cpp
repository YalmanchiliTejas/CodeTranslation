#include <bits/stdc++.h>
using namespace std;

int main(){
  string s = "consonant";
  char a;
  cin >> a;
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
    s = "vowel";
  cout << s << endl;
}

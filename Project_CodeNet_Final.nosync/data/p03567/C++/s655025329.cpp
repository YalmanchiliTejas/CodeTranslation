#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
string s;
int main(){
  cin >> s;
  bool ac=false;
  for (size_t i = 0; i < s.length()-1; i++) {
    if(s[i] == 'A'&&s[i+1] == 'C')ac = true;
  }
  cout << (ac ? "Yes":"No") << endl;
}

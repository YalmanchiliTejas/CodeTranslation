#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
 
  string result = "consonant";
  char val = S.at(0);
  if(val == 'a'||val == 'e'||
     val == 'i'||val == 'o'||val == 'u'
    ) result = "vowel";
  
  cout << result << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  if(S.at(0) == 'a' || S.at(0) == 'i' || S.at(0) == 'u' || S.at(0) == 'e' || S.at(0) == 'o'){ 
    cout << "vowel" << endl;
  } else {
  	cout << "consonant" << endl;
  }
}

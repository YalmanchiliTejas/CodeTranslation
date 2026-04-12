#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string c;
  bool ans = false;
  vector<string> vect = {"a","i","u","e","o"};
  cin >> c;

  for (int i = 0; i<5; i++){
    if (vect.at(i) == c){
      ans = true;
    }
  }

  if (ans){
    cout << "vowel" << endl;
  }
  else
  {
    cout << "consonant" << endl;
  }
}
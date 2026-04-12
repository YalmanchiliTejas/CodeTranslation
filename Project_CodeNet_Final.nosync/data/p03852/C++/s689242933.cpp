#include<iostream>
using namespace std;
 
int main () {
  char x;
  cin >> x;
  string n = "aeiou";
  for (int i = 0; i < n.length(); i ++){
    if (x == n[i]){
      cout << "vowel\n";
      return 0;
    }
  }
  cout << "consonant\n";
}
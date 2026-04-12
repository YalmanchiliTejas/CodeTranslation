#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;
  string judge = "consonant";
  
  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
    judge = "vowel";
  }
  

 
  cout << judge <<endl;
  
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char S[] = {'a','i','u','e','o'};
  char c;
  int x=0;
  cin >> c;
  for(int i = 0; i < 5; i++){
    if(c == S[i]){
      x++;
    }
  }
  if(x == 0){
    cout << "consonant" << endl;
  }
  else{
    cout << "vowel" << endl;
  }
}

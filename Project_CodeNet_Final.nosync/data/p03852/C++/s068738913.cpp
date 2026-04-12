#include <bits/stdc++.h>
using namespace std;
#define fg(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  char s;
  
  cin >> s;
  
  switch(s){
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel" << endl;
      break;
    default:
      cout << "consonant" <<endl; 
      break;
  }
}

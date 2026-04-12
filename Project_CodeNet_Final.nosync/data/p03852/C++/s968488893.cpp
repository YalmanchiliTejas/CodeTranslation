#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
 
  if(S=="a" || S=="i" || S=="u" || S=="e" || S=="o") 
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}

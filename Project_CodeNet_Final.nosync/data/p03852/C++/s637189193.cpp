#include <bits/stdc++.h>
using namespace std;

int main(){
  string n;
  string ans = "consonant";
  cin >> n;
  if (n=="a" || n=="i" || n=="u" || n=="e" || n=="o") ans = "vowel";
  cout << ans << endl;  
}
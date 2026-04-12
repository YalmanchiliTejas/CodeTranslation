#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  char a;
  cin >> a;
  string ans = "consonant";
  
  if (a == 'a') ans = "vowel";
  if (a == 'i') ans = "vowel";
  if (a == 'u') ans = "vowel";
  if (a == 'e') ans = "vowel";
  if (a == 'o') ans = "vowel";
  
  cout << ans << endl;
}
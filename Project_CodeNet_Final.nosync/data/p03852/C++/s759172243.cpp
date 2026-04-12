#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  char c;
  cin >> c;
  
  if(c==97 || c==101 || c==105 || c==111 || c==117) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}

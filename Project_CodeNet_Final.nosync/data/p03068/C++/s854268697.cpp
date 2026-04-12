#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string s;
  cin >> N >> s >> K;

  char C = s[K-1];
  for(int i=0; i<s.length(); i++){
    if(s[i] != C)
      s[i] = '*';
  }

  cout << s << endl;
}
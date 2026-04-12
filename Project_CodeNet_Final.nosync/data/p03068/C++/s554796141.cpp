#include <bits/stdc++.h>
using namespace std;

int main() {
  int len;
  string str;
  int k;
  cin >> len >> str >> k;
  
  char c = str[k-1];
  for(int i=0; i<len; ++i) {
    cout << (str[i] == c ? c : '*');
  }
  cout << endl;
}

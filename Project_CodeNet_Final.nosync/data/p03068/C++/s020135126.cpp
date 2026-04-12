#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#define _for(i,n) for(int i = 0; i < n; i++)

using namespace std;



int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  char kc = s[k-1];
  _for(i,n) {
    if (s[i]!=kc) {
      s[i] = '*';
    }
  }
  cout << s << endl;

}
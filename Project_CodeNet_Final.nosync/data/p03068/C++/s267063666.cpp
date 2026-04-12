#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long int

int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  char x = s[k - 1];
  for ( int i = 0; i < n; i++ ) {
    if ( s[i] != x ) cout << '*';
    else cout << s[i]; 
  }
  cout << endl;
  return 0;
}


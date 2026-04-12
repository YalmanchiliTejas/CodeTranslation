#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n, maxsofar=0, curr, s=0;
  cin >> n;
  while(n--) {
    cin >> curr;
    if(maxsofar<=curr) {
      maxsofar=curr;
      s++;
    }
  }
  cout << s;
}
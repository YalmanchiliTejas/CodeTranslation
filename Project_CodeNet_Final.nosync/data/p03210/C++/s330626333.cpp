#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  switch(n) {
    case 3:
    case 5:
    case 7:
      cout << "YES" << endl;
      break;
    default:
      cout << "NO" << endl;
  }
}
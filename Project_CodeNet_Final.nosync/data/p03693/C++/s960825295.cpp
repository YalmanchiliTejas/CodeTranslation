#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (((A * 100 + B * 10 + C) % 4) == 0)
  {
    cout << "YES" << endl; 
  } else {
    cout << "NO" << endl;
  }
}

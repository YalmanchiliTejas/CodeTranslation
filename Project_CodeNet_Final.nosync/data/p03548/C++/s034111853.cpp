#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z;cin>>x>>y>>z;
  x -= z;
  int n = x / (y+z);
  cout << n;
}

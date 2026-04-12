#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,y;
  cin >> n;
  x=800*n;
  y=200*((n-(n%15))/15);
  cout << x-y <<endl;
}
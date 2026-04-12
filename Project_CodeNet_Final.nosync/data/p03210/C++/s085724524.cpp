#include <bits/stdc++.h>
using namespace std;

int f(int n){
 if(n % 2 == 0) return n / 2;
  else return 3 * n + 1;
}

int main(void){
  int X;
  cin >> X;
  if(X == 3 || X == 5 || X == 7) cout << "YES";
  else cout << "NO";
  return 0;
}
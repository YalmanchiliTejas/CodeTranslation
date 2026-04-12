#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  int n;
  cin >> n;
  int x = n/15;
  cout << (800*n-200*x) << endl;
  return 0;
}
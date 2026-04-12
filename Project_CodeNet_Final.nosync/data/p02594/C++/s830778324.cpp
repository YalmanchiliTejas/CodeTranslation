#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int X;
  cin >> X;

  cout << (X < 30 ? "No" : "Yes") << endl;

  return 0;
}

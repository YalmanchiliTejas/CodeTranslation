
#include <bits/stdc++.h>

#define rep(i,n)  for(int i = 0; i < (int)(n); i++)
#define sz(x)     ((int)(x).size())
#define all(x)    (x).begin(),(x).end()

using ll = long long;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int X; std::cin >> X;
  if ( X >= 30 ) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}


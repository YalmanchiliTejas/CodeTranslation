// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

vector<ll> ALL(51, 0);
vector<ll> P(51, 0);

/*
xが1の時: 0
x>=All(n)の時: All(n)
x<=1+P(n-1)の時: g(n-1, x-1)
x==1+P(n-1)+1: g(n-1, x-2) + 1
x<=1+P(n-1)+1+P(n-1): g(n-1, x-2-P(n-1)) + 1 + P(n-1)

   P P     P P
  B P B   B P B
B       P       B

P_0 = 1, P_1 = 3, P_2 = 7
2 7

*/


ll g(int n, ll x) {
  if (n == 0) return 1;
  if (x == 1) return 0;
  if (x <= 1 + ALL[n-1]) return g(n-1, x-1);
  if (x == 1 + ALL[n-1] + 1) return g(n-1, x-2) + 1;
  if (x <= 1 + ALL[n-1] + 1 + ALL[n-1]) return P[n-1] + 1 + g(n-1, x-2-ALL[n-1]);
  return P[n];
}

int main() {
  int n; ll x; cin >> n >> x;
  ALL[0] = P[0] = 1;
  loop(i,1,n+1) ALL[i] = ALL[i-1] * 2 + 3;
  loop(i,1,n+1) P[i] = P[i-1] * 2 + 1;
  cout << g(n, x) << endl;
  return 0;
}

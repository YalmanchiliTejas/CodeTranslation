#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  if(X>=Y)
  {
    cout << min(A*X+B*Y,C*2*Y+min(A*(X-Y),C*2*(X-Y))) << endl;
  }
  else
  {
    cout << min(A*X+B*Y,C*2*X+min(B*(Y-X),C*2*(Y-X))) << endl;
  }
  return 0;
}

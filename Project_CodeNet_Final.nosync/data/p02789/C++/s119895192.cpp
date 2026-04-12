#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  ll n, m ;
  cin >> n >> m;
  if (n != m ) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rrep(i,n) for (int i=1; i<=(n); ++i)
#define drep(i,n) for (int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for (int i=s; i<t; ++i)
#define pu push_back
#define po pop_back
#define pi (acos(-1))
#define fast ios::sync_with_stdio(false); cin.tie(0)
//#define pii pair<int,int>
//#define pll pair<ll,ll>
#define vec vector
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> P;
const int INF = 1001001001;

//gcd & lcm
ll gcd (ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}
ll lcm (ll a, ll b) {
  return a/gcd(a,b)*b;
}

int main(void) {
  int n;
  cin >> n;
  if (n >= 30) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

ll a[55];
ll p[55];

ll thick(ll n) {
  if(n==0) return 1LL;
  return 2LL*thick(n-1LL)+3LL;
}

ll pn(ll n) {
  if(n==0) return 1LL;
  return 2LL*pn(n-1LL)+1LL;
}

ll f(ll n, ll x) {
  if(n==0) {
    if(x<=0) return 0LL;
    else return 1LL;
  }
  else if(x==1) return 0LL;
  else if(1<x && x<=1+a[n-1]) return f(n-1,x-1);
  else if(x==2+a[n-1]) return p[n-1]+1;
  else if(2+a[n-1]<x && x<=2+2*a[n-1]) return p[n-1]+1LL+f(n-1,x-2-a[n-1]);
  else if(x==3+2*a[n-1]) return 2*p[n-1]+1LL;
}

int main() {
  ll n, x;
  cin >> n >> x;
  rep(i,55) a[i] = thick(i);
  rep(i,55) p[i] = pn(i);
  cout << f(n,x) << endl;
  return 0;
}
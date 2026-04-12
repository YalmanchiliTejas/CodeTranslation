#include <bits/stdc++.h>
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,b) for(int i=a; i<=b; i++)
using ll = long long;
#define pb push_back
#define INF 100100100
//const int INF = 100100100;
const int MOD = (int) 1e9 + 7;
const double EPS = 1e-9;

int main()
{
  int N;
  cin >> N;
  vector<ll> a;
  rep(i,N) {
    ll tmp;
    cin >> tmp;
    a.pb(tmp);
  }
  vector<ll> b;
  b = a;
  sort(ALL(a));
  int naka_l = N/2 - 1;
  int naka_r = N/2 ;
  ll l_v = a[naka_l];
  ll r_v = a[naka_r];
  rep(i,N) {
    if (b[i] <= l_v) {
      cout << r_v << endl;
    } else if (b[i] >= r_v) {
      cout << l_v << endl;
    }
  }

}
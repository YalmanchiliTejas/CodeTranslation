#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;

vector<ll> bg(51), p(51);

ll f(ll n, ll x){
  if(n == 0) return p[0];
  if(x == 1) return 0;
  if(1 < x && x <= bg[n-1]+1) return f(n-1, x-1);
  if(x == bg[n-1]+2) return p[n-1]+1;
  if(bg[n-1]+2 < x && x <= 2*bg[n-1]+2) return p[n-1]+1 + f(n-1, x-bg[n-1]-2);
  if(x == bg[n]) return p[n];
}

int main(void){
  ll n, x;
  cin >> n >> x;

  bg[0] = 1;
  p[0] = 1;
  REP(i, n){
    bg[i+1] = 2*bg[i]+3;
    p[i+1] = 2*p[i]+1;
  }
  cout << f(n, x) << endl;
  return 0;
}
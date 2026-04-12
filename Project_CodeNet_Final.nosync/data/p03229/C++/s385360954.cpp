#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<pll> vpl;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  vll a(n);
  REP(i, n)
    cin >> a[i];

  sort(a.begin(), a.end());
  deque<ll> deq1, deq2;
  REP(i, n){
    deq1.push_back(a[i]);
    deq2.push_back(a[i]);
  }

  ll l = 0;
  ll r = n-1;
  bool fc = false;
  vll pre(2);
  pre[0] = pre[1] = a[l];
  l++;
  ll ans1 = 0;
  while(l <= r){
    if(!fc){
      ans1 += a[r] - pre[1];
      pre[1] = a[r];
      r--;
      if(l > r)
        break;
      ans1 += a[r] - pre[0];
      pre[0] = a[r];
      r--;
      fc = true;
    }
    else{
      ans1 += pre[1]-a[l];
      pre[1] = a[l];
      l++;
      if(l > r)
        break;
      ans1 += pre[0]-a[l];
      pre[0] = a[l];
      l++;
      fc = false;
    }
  }



  l = 0;
  r = n-1;
  fc = true;
  pre[0] = pre[1] = a[r];
  r--;
  ll ans2 = 0;
  while(l <= r){
    if(!fc){
      ans2 += a[r] - pre[1];
      pre[1] = a[r];
      r--;
      if(l > r)
        break;
      ans2 += a[r] - pre[0];
      pre[0] = a[r];
      r--;
      fc = true;
    }
    else{
      ans2 += pre[1]-a[l];
      pre[1] = a[l];
      l++;
      if(l > r)
        break;
      ans2 += pre[0]-a[l];
      pre[0] = a[l];
      l++;
      fc = false;
    }
  }

  cout << max(ans1, ans2) << endl;



}

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
        #define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
  P
  B P P P B
  B BPPPB P BPPPB B

  f(n+1) = B f(n) P f(n) B
*/

ll dfs(ll a, ll b)
{
  if(a == 0) return 1;

  ll res = 0;
  ll n = (1LL<<(a+2))-3;

  if(b >= n/2){
    res += (1LL<<a)-1;
    if(b == n){
      res += (1LL<<a)-1;
    }else if(b > n/2+1){
      res += dfs(a-1, b-n/2-1);
    }
  }else{
    if(b > 1){
      res += dfs(a-1, b-1);
    }
  }

  if(b > n/2){
    res++;
  }
  
  return res;
}

int main()
{
  ll n, x;
  cin >> n >> x;

  cout << dfs(n, x) << endl;

  return 0;
}

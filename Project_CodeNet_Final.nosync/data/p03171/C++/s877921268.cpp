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
*/

int n;
ll a[3000];
ll memo[3001][3001];
bool used[3001][3001];

ll dfs(int l, int r)
{
  if(l > r) return 0;
  if(used[l][r]) return memo[l][r];
  used[l][r] = true;

  ll res;
  if((n-(r-l+1))%2 == 0){
    res = -linf;
    res = max(res, dfs(l+1, r) + a[l]);
    res = max(res, dfs(l, r-1) + a[r]);
  }else{
    res = linf;
    res = min(res, dfs(l+1, r) - a[l]);
    res = min(res, dfs(l, r-1) - a[r]);
  }

  return memo[l][r] = res;
}

int main()
{
  cin >> n;
  
  rep(i, n){
    cin >> a[i];
  }

  cout << dfs(0, n-1) << endl;

  return 0;
}

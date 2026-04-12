#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

vl len;
vl p;

ll dfs(int n,ll x) {
  ll l = len[n];
  
  if(l <= x) return p[n];
  if(x == 0) return 0;
  if((l+1)/2 <= x) {
    ll ans = 0;
    ans += p[n-1];
    ans++;
    ans += dfs(n-1,x-(l+1)/2);
    return ans;
  }
  return dfs(n-1,x-1);
}
  
int main() {
  int N;
  ll X;
  cin >> N >> X;
  len = vl(N+1,1);
  srep(i,1,N+1){
    len[i] = 3 + 2 * len[i-1];
  }
  p = vl(N+1,1);
  srep(i,1,N+1) {
    p[i] = 1 + p[i-1] * 2;
  }
  cout << dfs(N,X) << endl;
  return 0;
}
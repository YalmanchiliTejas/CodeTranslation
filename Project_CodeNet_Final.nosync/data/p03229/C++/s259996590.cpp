#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
  ll n;
  scanf("%lld", &n);
  ll a[n];
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  ll ansa = 0;
  ll ansb = 0;

  sort(a,a+n);
  // FOR(i,0,n-1) cout << a[i] << endl;

  int x = ((n-2)+1)/2;
  // cout << x << endl;

  FOR(i,0,x-1){
    ansa += a[i]*(-2);
  }
  // cout << ansa << endl;
  if(n%2==0) ansa -= a[x];
  else ansa += a[x];
  ansa += a[x+1];
  // cout << ansa << endl;
  FOR(i,x+2,n-1){
    ansa += a[i]*2;
  }
  // cout << ansa << endl;

  sort(a,a+n,greater<ll>());

  FOR(i,0,x-1){
    ansb += a[i]*(2);
  }
  FOR(i,x,x+1){
    ansb -= a[i];
  }
  if(n%2==0) ansb += a[x+1]*2;
  FOR(i,x+2,n-1){
    ansb += a[i]*(-2);
  }


  // cout << ansa << " " << ansb << endl;
  cout << max(ansa,ansb) << endl;


}


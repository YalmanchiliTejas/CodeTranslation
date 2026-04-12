#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define INF 1000000001
#define INFL (1LL << 60)
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  REP(i, n) cin >> a[i];
  REP(i, n) b[i] = a[i];
  sort(b, b+n);
  int r = b[n/2-1], l = b[n/2];
  REP(i, n){
    if(a[i] <= r) cout << l << endl;
    else cout << r << endl; 
  }
  return 0;
}

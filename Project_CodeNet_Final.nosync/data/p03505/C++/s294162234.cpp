#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define INF 1000000000
#define INFL 10000000000000000LL
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<ll, ll>

int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  if(a <= b){
    if(k <= a) cout << 1 << endl;
    else cout << -1 << endl;
  }
  else if(k <= a) cout << 1 << endl;
  else cout << 1+(2*(1 + (k-a-1)/(a-b))) << endl;
  return 0;
}

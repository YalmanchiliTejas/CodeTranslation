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
  while(true){
    int n;
    cin >> n;
    if(n == 0) return 0;
    int a[n];
    REP(i, n) cin >> a[i];
    sort(a, a+n);
    int sum = 0;
    FOR(i, 1, n-1){
      sum += a[i];
    }
    cout << sum/(n-2) << endl;
  }
  return 0;
}


#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define MOD 1000000007
#define MAX 100010
#define aout(a) REP(i,sizeof(a)) cout << a[i] << " "; cout << endl;
#define vout(v) REP(i,v,size()) cout << v[i] << " "; cout << endl;
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
  int N; cin>>N;
  vector<ll> A(N);
  REP(i,N) cin>>A[i];
  ll ans = 0;
  vector<ll> sum(N-1);
  sum[0] = A[0];
  FOR(i,1,N-1){
    sum[i] = (sum[i-1] + A[i]) % MOD;
  }
  REP(i,N-1){
    int tmp = (A[i+1] * sum[i]) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans;
}
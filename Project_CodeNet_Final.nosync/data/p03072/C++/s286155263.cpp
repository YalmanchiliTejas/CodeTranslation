#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long int ll;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }return 0; }
#define all(a)  (a).begin(),(a).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
const ll INF =1LL << 62;
int main(){
  int N; cin >> N;
  vector<int> H(N);
  cinf(N,H);
  int ans=0;
  int max=H[0];
  rep(i,N){
    if(max <= H[i]) ans ++;
    chmax(max,H[i]);
  }
  cout << ans << endl;
}
  
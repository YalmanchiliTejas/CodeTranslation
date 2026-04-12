#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,int>;
const ll INF = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  ll cnt =0;
  ll ans =0;
  rep(i,n) {
    cin >> A[i];
    ans = ans%INF+A[i]*cnt;
    cnt = cnt%INF+A[i];
  }
  cout << ans % INF << endl;
  return 0;

}

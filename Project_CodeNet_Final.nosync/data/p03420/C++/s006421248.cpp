#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  ll cnt = 0;
  for(ll i=k+1; i<=n; i++){
    if(n%i == 0) cnt += (i-k)*(n/i);
    else{
      cnt += (i-k)*(n/i);
      if(n%i>=k) cnt += n%i-k+1;
      if(k == 0) cnt--;
    }
  }
  cout << cnt << endl;
  return 0;
}
#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,a,b) for(int i = a; i < (b); i++)
#define P pair<int, int>
using namespace std;

const int64_t mod = 1000000007;

int main() { 
  int64_t n, sum = 0, ans = 0, b;
  cin >> n;
  vector<int64_t> a(n);
  rep(i,0,n){
    cin >> a[i];
    sum += a[i];
  }
  rep(i,0,n-1){
    sum -= a[i];
    b = sum % mod;
    ans += a[i] * b;
    ans %= mod;
  }
  cout << ans << endl;
}

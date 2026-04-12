#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)


/*
https://maspypy.com/atcoder-%E5%8F%82%E5%8A%A0%E6%84%9F%E6%83%B3-2019-03-22abc-159


ans = sum_(i<=j){ f(i,j) }
  
    = f(1,1) +f(1,2) +f(1,3) +...
             +f(2,2) +f(2,3) +...
                     +f(3,3) +...

形式的べき級数で考えると


f(i,j-1) {i<j} について *(x^A[j] + 1) をやることで f(i,j) の分を足す
(x^A[j] + 1)を足すことで f(j,j) を足す

*/


int main(){
  ll ans = 0;
  ll mod = 998244353;
  ll N,S;
  cin >> N >> S;
  vector<ll> coefficient(3003,0);
  FOR(i,0,N){
    ll a;
    cin >> a;
    vector<ll> t = coefficient;
    FOR(j,a,S+1){
      (t[j] += coefficient[j-a]) %= mod;
    }
    t[a]++;
    t[0]++;
    coefficient = t;
    (ans += coefficient[S]) %= mod;
  }
  cout << ans << endl;
}

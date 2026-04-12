#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
  ll N,mod=1000000007,sum=0,ans=0,temp;
  cin >> N;
  vector<ll> A(N);
  rep(i,N)
  {
    cin >> A[i];
    sum += A[i];
    sum = sum % mod;
  }
  temp = sum + mod;
  rep(i,N)
  {
    if(temp-A[i]<0)
      temp = temp - A[i]+mod;
      else
        temp = temp - A[i];

    ans = (ans+((temp % mod) * A[i]) % mod)%mod;
  }

  cout << ans << endl;
  return 0;
}

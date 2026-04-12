typedef long long int ll;
typedef unsigned long long int ull;
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define sec second
#define fir first
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repe(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define entire(a) (a).begin(),(a).end()
#define pb push_back
#define pii pair<int,int>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
void solve()
{
  ll n;
  cin >> n;
  std::vector<ll> v(n);
  std::vector<ll> s(n);
  rep(i, n)cin >> v[i];
  s[0] = v[0];
  repe(i, 1, n) {
    s[i] = (s[i - 1] + v[i]) % MOD;
  }
  ll sum = 0;
  // rep(i,n)
  // cout<<s[i]<<" ";
  // cout<<endl;
  repe(i,1, n) {
    // if(i==0)
    // sum=(v[i]*s[i])%MOD;
    // else
    sum += (v[i] * s[i - 1]) % MOD;
    sum %= MOD;
  }
  cout << sum << endl;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl
#define readVarll(nam) ll nam; cin >> nam

#define DEV_VAL 1000000007
ll mulbig(ll a, ll b)
{
  return (a * b) % DEV_VAL; 
}

ll addbig(ll a, ll b)
{
  return (a + b) % DEV_VAL;
}

int main()
{
  ll n;
  cin >> n;
  ll mydata[n];
  rep(i, n) cin >> mydata[i];

  ll ans = 0;
  ll tmpadd = mydata[0];
  reps(i, 1, n)
  {
    ans = addbig(ans, mulbig(tmpadd, mydata[i]));
    tmpadd = addbig(tmpadd, mydata[i]);
  }

  cout << fixed << ans << endl;

  return 0;
}
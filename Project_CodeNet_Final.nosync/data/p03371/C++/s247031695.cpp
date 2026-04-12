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

int main()
{
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  if(x < y)
  {
    swap(a, b);
    swap(x, y);
  }

  ll val = 0;
  if(a + b >= 2 * c)
  {
    val += c * 2 * y;
  }
  else
  {
    val += (a + b) * y;
  }
  
  if(a >= 2 * c)
  {
    val += (x-y) * 2 * c;
  }
  else
  {
    val += (x - y) * a;
  }

  cout << fixed << val << endl;

  return 0;
}
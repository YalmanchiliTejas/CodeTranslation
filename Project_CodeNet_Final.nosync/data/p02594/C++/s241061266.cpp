#include <bits/stdc++.h>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl

string yesNo(bool val)
{
  if(val)
  {
    return "Yes";
  }
  else {
    return "No";
  }
}
int main()
{
  int a;
  cin >> a;
  int ans = a;

  cout << fixed << yesNo(a >= 30) << endl;
  return 0;
}
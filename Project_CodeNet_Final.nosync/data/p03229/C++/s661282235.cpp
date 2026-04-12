#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  rep(i,n) cin >> a[i];
  sort(all(a));
  ll inc = 0;
  ll dec = 0;
  ll ans = 0;
  if(n%2 == 0)
  {
    int low = n/2;
    int high = n-low;
    rep(i,low)
    {
      if(i == low-1) dec += a[i];
      else dec += a[i] *2;
    }
    rep(i,high)
    {
      if(i == 0) inc += a[low+i];
      else inc += a[low+i]*2;
    }
    ans = max(ans, inc-dec);
  }
  else
  {
    int low = n/2;
    int high = n-low;
    rep(i,low)
    {
      dec += a[i] *2;
    }
    rep(i,high)
    {
      if(i <= 1) inc += a[low+i];
      else inc += a[low+i]*2;
    }
    ans = max(ans, inc-dec);
    swap(low,high);
    inc = 0;
    dec = 0;
    rep(i,low)
    {
      if(i >= low-2) dec += a[i];
      else dec += a[i]*2;
    }
    rep(i,high)
    {
      inc += a[low+i]*2;
    }
    ans = max(ans, inc-dec);
  }
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,k;
  cin >> n >> k;
  ll ans = 0;
  int b;
  for(b=k+1;b<=n;b++)
  {
    int full = n/b;
    int marg = n%b;
    ans += full*(b-k);
    ans += max(marg-k+1,0);
    if(k == 0)ans--;
  }
  cout << ans << endl;
}
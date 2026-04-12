#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>

#define ll long long

using namespace std;

ll mod = 1e9 + 7;

void
solve() {
  string s;
  ll d;
  cin>>s>>d;

  vector<ll> dp(105, 0), temp(105, 0);
  ll last = 0, n = s.length();
  for (ll i=0; i<n; i++) {
    temp = vector<ll>(105, 0);
    if (i==0) {
      for (ll j=0; j<s[i]-'0'; j++) temp[j%d]++;
    }
    else {
      for (ll j=0; j<10; j++) {
        if (j < s[i]-'0') { 
          temp[(j+last)%d]++;
          temp[(j+last)%d] %= mod;
        }
        for (ll k=0; k<d; k++) {
          temp[(j+k)%d] += dp[k];
          temp[(j+k)%d] %= mod;
        }
      }
    }
    swap(dp, temp);
    last += s[i] - '0';

    //for (auto k : dp) cout<<k<<","; cout<<endl;
  }
  dp[last % d]++;
  cout<<(dp[0]-1 + mod) % mod<<endl;
}

int
main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);

  ll t = 1;
  //cin>>t;

  while (t > 0) {
    t--;
    solve();
  }

  return 0;
}


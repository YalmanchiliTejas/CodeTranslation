#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//using Graph = vector<vector<int>>;
//#define pi 3.1415926535

const int MOD = 1000000007;

int main()
{
  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> s(n);

  cin >> a[0];
  s[0] = a[0];
  for(int i = 1; i < n; i++){
    cin >> a[i];
    s[i] = s[i - 1] + a[i]; 
    s[i] = s[i] % MOD;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    if(s[n - 1] >= s[i]){
      ans += a[i] * (s[n - 1] - s[i]);
    }
    else{
      ans += a[i] * (MOD + s[n - 1] - s[i]);
    }
    ans = ans % MOD;
  }

  cout << ans << endl;

  return 0; 
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  const long long MOD = 1000000007;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  sum%=MOD;

  long long ans = 0;
  for (int i = 0; i < n-1; i++)
  {
    sum+=MOD - a[i];
    sum%=MOD;
    long long add = (a[i]*sum)%MOD;
    ans+=add;
    ans%=MOD;
  }
  cout << ans << endl;
}
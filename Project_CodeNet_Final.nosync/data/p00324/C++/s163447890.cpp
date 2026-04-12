
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  map<long long, long long> mp;
  long long sum = 0;
  long long ans = 0;
  mp[0] = 0;
  for(int i = 1; i <= N; i++) {
    long long d;
    cin >> d;
    sum += d;
    if(mp.count(sum)) ans = max(ans, i-mp[sum]);
    else mp[sum] = i;
  }
  cout << ans << endl;
  return 0;
}
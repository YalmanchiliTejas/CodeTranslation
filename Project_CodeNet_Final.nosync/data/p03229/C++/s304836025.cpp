#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  ll res = 0;
  if(n % 2 == 1){
    ll now = 0;
    for(int i = 0;i < n / 2;i++)now -= a[i] * 2;
    for(int i = 0;i < n / 2 + 1;i++){
      now += a[a.size() - 1 - i] * 2;
      if(i >= n / 2 - 1)now -= a[a.size() - 1 - i];
    }
    res = max(res,now);
    now = 0;
    for(int i = 0;i < n / 2;i++)now += a[a.size() - 1 - i] * 2;
    for(int i = 0;i < n / 2 + 1;i++){
      now -= a[i] * 2;
      if(i >= n / 2 - 1)now += a[i];
    }
    res = max(res,now);
  }
  else{
    ll now = 0;
    for(int i = 0;i < n / 2;i++)now += a[a.size() - 1 - i] * 2;
    now -= a[a.size() - n / 2];
    for(int i = 0;i < n / 2;i++)now -= a[i] * 2;
    now += a[n / 2 - 1];
    res = max(res,now);
  }
  cout << res << endl;
  return 0;
}
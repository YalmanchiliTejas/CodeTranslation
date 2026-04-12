#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli n;
vll a;
vll s;
lli ans = 0;

int main(){
  cin >> n;
  a = vll(n);
  for(lli i = 0;i < n;i++) cin >> a[i];
  s = vll(n);
  while(true){
    for(lli i = 0;i < n;i++){
      s[i] = a[i]/n;
      a[i] = a[i]%n;
      a[i] -= s[i];
    }
    lli k = accumulate(s.begin(),s.end(),0ll);
    if(k == 0) break;
    ans += k;
    for(lli i = 0;i < n;i++){
      a[i] += k;
    }
  }
  cout << ans << endl;
  return 0;
}

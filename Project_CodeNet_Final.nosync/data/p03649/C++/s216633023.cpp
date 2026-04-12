#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;
typedef vector<unordered_map<lli,lli>> graph;

lli n;
vll a;
vll b;
lli ans = 0;

int main(){
  cin >> n;
  a = vll(n);
  for(lli i = 0;i < n;i++) cin >> a[i];
  while(true){
    b = vll(n);
    for(lli i = 0;i < n;i++){
      b[i] = a[i]/n;
      a[i] %= n;
    }
    lli c = accumulate(b.begin(),b.end(),0ll);
    if(c == 0) break;
    ans += c;
    for(lli i = 0;i < n;i++){
      a[i] += c-b[i];
    }
  }
  cout << ans << endl;
  return 0;
}

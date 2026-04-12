#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;
typedef vector<unordered_map<lli,lli>> graph;

lli n,k;
lli ans;

int main(){
  cin >> n >> k;
  if(k == 0){ cout << n*n << endl;return 0;}
  for(lli i = k+1;i <= n;i++){
    ans += (i-k)*(n/i);
    if(n%i != 0) ans += max(n%i+1,k)-k;
  }
  cout << ans << endl;
  return 0;
}

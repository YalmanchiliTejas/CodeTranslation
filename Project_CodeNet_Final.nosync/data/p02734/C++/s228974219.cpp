#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <random>
#include <stack>
#include <set>
#include <unordered_set>

#define bug(x) cout<<"zdongdebug1: "<<x<<endl;
#define bug2(x, y) cout<<"zdongdebug2: "<<x<<" "<<y<<endl;
#define bug3(x, y, z) cout<<"zdongdebug3: "<<x<<" "<<y<<" "<<z<<endl;
using namespace std;
typedef long long ll;
const int maxn = 3005;
const int mod = 998244353;

int n,m;
int a[maxn];

ll f[maxn][maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  cin>>n>>m;
  ll ret = 0;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
    if(a[i]<=m) {
      ret = (ret + (n - i + 1) * f[i - 1][m - a[i]]%mod)%mod;
      if(a[i]==m){
        ret = (ret + i * ll(n-i+1)%mod)%mod;
      }
    }
    for(int j=1;j<=m;j++){
      f[i][j] = f[i-1][j];
      if(j-a[i]>=1)f[i][j] = (f[i][j]+f[i-1][j-a[i]])%mod;
    }
    if(a[i]<=m)f[i][a[i]] = (f[i][a[i]] + i)%mod;
  }
  cout<<ret<<endl;
  return 0;
}
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
const int maxn = 200005;
const int mod = 1000000007;

int n;
int a[maxn];
ll f[maxn][2][5];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=0;i<maxn;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<5;k++)f[i][j][k] = -(1LL<<60);
  f[0][0][1] = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<5;k++){
        if(f[i][j][k]==-(1LL<<60))continue;
        if(j){
          if(k+1<5&&f[i+1][0][k+1]<f[i][j][k]){
            f[i+1][0][k+1] = f[i][j][k];
          }
          continue;
        }
        if(k+1<5&&f[i+1][0][k+1]<f[i][j][k]){
          f[i+1][0][k+1] = f[i][j][k];
        }
        if(k-1>=0&&f[i+1][1][k-1]<f[i][j][k]+a[i+1]){
          f[i+1][1][k-1]=f[i][j][k]+a[i+1];
        }
      }
  int tt = n/2;
  int df = (n-tt)-tt;
  cout<<max(f[n][0][df+1], f[n][1][df+1])<<endl;
  return 0;
}
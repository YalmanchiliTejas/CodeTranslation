#include <cstdio>
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
const int maxn = 105;
const int mod = 1000000007;

int f[maxn][2][4];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  string s;
  int n;
  cin>>s>>n;
  f[0][1][0] = 1;
  for(int i=0;i<s.size();i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<=n;k++){
        if(!f[i][j][k])continue;
        for(int r=0;r<10;r++){
          if(k==n&&r)continue;
          if(j&&r>s[i]-'0')continue;
          f[i+1][j&&r==s[i]-'0'][k+(r>0)]+=f[i][j][k];
        }
      }
  cout<<f[s.size()][0][n]+f[s.size()][1][n]<<endl;
  return 0;
}
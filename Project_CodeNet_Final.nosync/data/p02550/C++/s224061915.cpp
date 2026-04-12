#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
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
const int maxn = 100005;
const int mod = 998244353;

int f[maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
 ll n;
 int x, m;
 cin>>n>>x>>m;
 unordered_map<int,int>mp;
 mp[x] = 1;
 ll cur = x;
 ll sum = x;
 f[1] = x;
 for(ll i=2;i<=n;i++){
   int tt = cur*cur%m;
   f[i] = tt;
   if(mp.find(tt)!=mp.end()){
     int len = i-mp[tt];
     ll cc = 0;
     for(int j=mp[tt];j<i;j++){
       cc = (cc+f[j]);
     }
     ll lft = n-i+1;
     ll tmp = lft/len;
     sum+=tmp*cc;
     lft%=len;
     for(int j=mp[tt];j<mp[tt]+lft;j++){
       sum+=f[j];
     }
     break;
   }
   cur = tt;
   sum = (sum+tt);
   mp[tt] = i;
 }
 cout<<sum<<endl;
 return 0;
}

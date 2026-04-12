#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double dd;
const int N = 1e6+5;
const dd eps = 1e-8;
const int mod = 1e9+7;
ll a[N],n,ans,sum[N];

int main(){
  ios::sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
  cin>>n;
  for(int i = 1;i <= n;i++) cin>>a[i];
  for(int i = 1;i <= n;i++) sum[i] = (sum[i-1] + a[i])%mod;
  for(int i = 1;i <= n;i++){
    ans = (ans + (a[i]*((sum[n]-sum[i] + mod)%mod))%mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1005;
const int mod = 1000000007;

void gcd(ll a,ll b, ll& d,ll& x,ll& y) { //      已经测试 FZU 1402
  if(!b) {
    d=a;
    x=1;
    y=0;
  } else   {
    gcd(b,a%b,d,y,x);
    y-=a/b*x;
  }
}

ll inv(ll a,ll n)  { //无逆元返回-1
  ll d,x,y;
  gcd(a,n,d,x,y);
  return d==1?(x%n+n)%(n/d):-1;
}

ll cc[maxn][maxn],f[maxn][maxn];
void init() {
  for(int i=0; i<maxn; i++)cc[i][0]=cc[i][i]=1;
  for(int i=1; i<maxn; i++)
    for(int j=1; j<i; j++)
      cc[i][j]=(cc[i-1][j]+cc[i-1][j-1])%mod;
}

int main() {
  //freopen("in.cpp","r",stdin);
  init();
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  f[a-1][0]=1;
  for(int i=a-1; i<b; i++)
    for(int j=0; j<=n; j++) {
      f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
      ll fenzi = 1,fenmu=1;
      for(int k=1; k*(i+1)+j<=n&&k<c; k++) {
        fenmu = fenmu * k %mod;
        fenzi = fenzi * cc[n-j-(k-1)*(i+1)][i+1]%mod;
      }
      for(int k=c; k*(i+1)+j<=n&&k<=d; k++) {
        fenmu = fenmu * k %mod;
        fenzi = fenzi * cc[n-j-(k-1)*(i+1)][i+1]%mod;
        f[i+1][j+k*(i+1)]=(f[i+1][j+k*(i+1)]+f[i][j]*fenzi%mod*inv(fenmu,mod)%mod)%mod;
      }
    }
    cout<<f[b][n]<<endl;
  return 0;
}

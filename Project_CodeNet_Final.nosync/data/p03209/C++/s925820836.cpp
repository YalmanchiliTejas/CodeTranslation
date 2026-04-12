#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////

int pati(int n,int i){
  if(n==0&&i==1)return 1;
  if(i==0)return 0;
  if(i<=pow(2,n+1)-2) return pati(n-1,i-1);
  if(i==pow(2,n+1)-1) return pow(2,n);
  if(i>=pow(2,n+1)&&i!=pow(2,n+2)-3) return pow(2,n)+pati(n-1,i-(pow(2,n+1)-1));
  if(i==pow(2,n+2)-3) return pow(2,n+1)-1;
}
signed main() {
  int n,x;
  cin>>n>>x;
  cout<<pati(n,x)<<endl;
  }

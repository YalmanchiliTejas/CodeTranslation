#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> fac(300001); //n!(mod M)
vector<int> ifac(300001); //k!^{M-2} (mod M)

long long fpow(long long a,long long n){
  long long ret=1;
  if(n==1) return a;
  if(n%2==0) {
      ret = fpow(a*a%mod, n/2) %mod ;
  }else {
      ret = (a%mod)*fpow(a*a%mod, n/2) %mod;
  }
  return ret %mod;
}
int comb(int a, int b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

vector<int> ra(MX,0);
vector<int> par(MX,0);

signed main(){
    int n, m, k ;
    cin >> n >> m >> k;

    int ans = 0;
    for (size_t i = 0; i < m; i++)
    {
        ans += i*(m-i)*n*n;
    }
    for (size_t i = 0; i < n; i++)
    {
        ans += i*(n-i)*m*m;
    }

    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*fpow(i+1,mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    int cnb = comb(m*n-2, k-2);
    cout << (ans%mod*cnb)%mod << endl;
}
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<cassert>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long
//#define lint long long

const int INF = 1e9;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで




using namespace std;
int n,m,k;
int a;//各距離の数
int b;
int extgcd(int a, int b, int &x, int &y) {
    int g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int mod_fact(int n,int p,int& e){
  e = 0;
  if(n==0) return 1;
  int res = mod_fact(n/p,p,e);
  e += n/p;
  if(n/p%2 != 0){
    int t = 1;
    for(int i=1;i<=n;i++){
      t *= i;
      t %= p;
    }
    return res*(p-t)%p;
  }
  int t2=1;
  for(int i=1;i<=n;i++){
    t2 *= i;
    t2 %= p;
  }
  return res * t2%p;
}

int mod_inverse(int a,int m){
  int x,y;
  extgcd(a,m,x,y);
  return (m+x%m) %m;
}

int mod_comb(int n,int k,int p){
  if(n<0||k<0||n<k) return 0;
  int e1,e2,e3;
  int a1 = mod_fact(n,p,e1),a2 = mod_fact(k,p,e2),a3 = mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1 * mod_inverse(a2*a3%p,p)%p;
}


signed main(){
  cin >> n >> m >> k;
  if(m<n) swap(n,m);
  FOR(i,n){
    FOR(j,m){
      FOR(l,n){
        a += (2*abs(l-i)+(m-j))*(m-j+1)/2;
        a %= MOD;
        a += (2*abs(l-i)+(j-1))*(j)/2;
        a %= MOD;
        a += (MOD-abs(l-i));
        a %= MOD;
      }
    }
  }
  a *=500000004;
  a %= MOD;
  b = mod_comb(n*m-2,k-2,MOD);
  b %= MOD;
  cout << a*b%MOD << endl;
  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

ll num = 0;
vvl dat;//l, r, h
vvl G = VV(101, 0, 0, ll);
vll h;
ll INF = 10000000000;
void f(ll par, ll l, ll r){
  ll minnum = INF;
  ll L = l;
  for(int i=l;i<r;i++){
    if(h[i]==0){
      if(minnum!=INF){
        if(par!=-1) G[par].push_back(num);
        dat.push_back(vll{L, i, minnum});
        num++;
        for(int j=L;j<i;j++) h[j] -= minnum;
        f(num-1, L, i);
      }
      L = i+1;
      minnum = INF;
      continue;
    }else{
      minnum = min(minnum, h[i]);
    }

    if(h[i]!=0&&i==r-1){
      if(minnum!=INF){
        if(par!=-1) G[par].push_back(num);
        dat.push_back(vll{L, i+1, minnum});
        num++;
        for(int j=L;j<=i;j++) h[j] -= minnum;
        f(num-1, L, i+1);
      }
    }
  }
}
ll P = 1000000007;
ll mpow(ll a, ll b, ll p = -1){
  ll ret = 1, num = a;
  if(p==-1){
    while(b>0){
      if(b%2) ret *= num;
      num = num * num;
      b /= 2;
    }
  }else{
    while(b>0){
      if(b%2) ret = (ret*num)%p;
      num = (num*num)%p;
      b /= 2;
    }
  }
  return ret;
}
vll dp1(101, 0);
vll dp2(101, 0);

void dfs(ll now, ll from){
  ll cnt = 0;
  for(auto to:G[now]){
    if(to==from) continue;
    cnt++;
  }
  if(!cnt){
    dp1[now] = mpow(2, dat[now][2], P);
    dp2[now] =
    (mpow(2, dat[now][1]-dat[now][0], P) + (dp1[now] - 2) + P)%P;
    return;
  }

  ll W = dat[now][1] - dat[now][0];
  dp1[now] = 1, dp2[now] = 1;

  ll s = 1, t = 1;
  for(auto to:G[now]){
    if(to==from) continue;
    dfs(to, now);
    //子全てが1のとき1になれる
    W -= dat[to][1] - dat[to][0];
    dp1[now] = (dp1[now] * dp1[to])%P;
    s = (s * (dp1[to] + dp2[to])%P)%P;
    t = (t * dp1[to])%P;
  }

  dp1[now] = (dp1[now] * mpow(2, dat[now][2], P))%P;
  ll a = ((mpow(2, dat[now][2], P)-2+P)%P *t)%P;
  ll b =(mpow(2, W, P)*s)%P;
  dp2[now] = (a + b)%P;
}

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  h = vll(n);
  re(i, n) std::cin >> h[i];
  f(-1, 0, n);
  dfs(0, -1);
  std::cout << dp2[0] << '\n';
  return 0;
}

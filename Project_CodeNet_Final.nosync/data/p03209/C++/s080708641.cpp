#include <bits/stdc++.h>
using namespace std;

#define INF 1LL << 30;
typedef long long ll;

// Nバーガーは1+N-1バーガー+1+N-1バーガー+1
// Nバーガーの厚さはをl(N)とすると
// Nバーガーのパティーをp(N)とすると
// p(N) = 2*p(N-1) + 1
// l(N) = 2*l(N-1) + 3であり
// f(N,X)をパティの枚数とすると、
// f(N,X) = 0 (X=1)
// f(N,X) = f(N-1,X-1) ()
// f(N,X) = p(N-1)+1 (X=l(N-1)+2)
// f(N,X) = f(N-1,X-l(N-1)-2) + p(N-1)+1 ()
// f(N,X) = 2*p(N-1) + 1

ll N,X;
vector<ll> l,p;
ll rec(ll n, ll x);

int main() {

  cin >> N >> X;
  l = vector<ll>(N+1);
  p = vector<ll>(N+1);
  l[0] = 1;
  p[0] = 1;
  for (int i=0;i<N;i++){
    l[i+1] = 2*l[i]+3;
    p[i+1] = 2*p[i]+1;
  }
  cout << rec(N,X) << endl;
}

ll rec(ll n, ll x){
  if (n==0) {
    if (x<=0){
      return 0;
    } else {
      return 1;
    }
  }
  if (x==1){
    return 0;
  } else if (x<l[n-1]+2){
    return rec(n-1,x-1);
  } else if (x==l[n-1]+2){
    return p[n-1]+1;
  } else if (l[n-1]+2 < x && x < 2*l[n-1]+3){
    return rec(n-1,x-l[n-1]-2)+p[n-1]+1;
  } else {
    return 2*p[n-1]+1;
  }
}
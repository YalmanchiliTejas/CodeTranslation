#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll X[55],P[55];

void init(){
  X[0] = 1;
  rep(i,1,51) X[i] = 3LL + 2LL * X[i-1];
  P[0] = 1;
  rep(i,1,51) P[i] = 1LL + 2LL * P[i-1];
}

ll p=0;

void dfs(int l,ll x){ //レベルlバーガーの下からx層について
  if(x <= 1LL){
    if(l==0 && x==1)p++;
  }else if(x <= 1LL + X[l-1]){
    dfs(l-1,x-1LL);
  }else if(x <= 2LL + X[l-1]){
    p++;
    dfs(l-1,x-2LL);
  }else if(x <= 2LL + 2LL * X[l-1]){
    p++;
    p += P[l-1];
    dfs(l-1,x-2LL-X[l-1]);
  }else{
    p++;
    p += 2LL * P[l-1];
  }
}


int main(){
  init();
  int N;
  ll x;
  cin >> N >> x;

  dfs(N,x);

  cout << p << endl;

  return 0;
}

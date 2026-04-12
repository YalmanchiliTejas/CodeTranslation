#include <bits/stdc++.h>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define dbg(x) cout<<#x<<"="<<x<<endl
using ll=long long;

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N)cin>>A[i];

  set<ll> cands;
  for(ll num:A){
    repl(base,2,sqrt(num)+1){
      if(num%base==0 && num!=base){
        cands.insert(base);
        cands.insert(num/base);
      }
    }
    if(num!=1)cands.insert(num);
  }
  ll res=0;
  for(ll cand:cands){
    ll tres=0;
    for(ll num:A){
      if(num%cand==0){
        tres+=num;
      }
    }
    res=max(res,tres);
  }
  cout<<res<<endl;
  return 0;
}


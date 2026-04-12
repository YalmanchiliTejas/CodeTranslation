#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=998244353;
const long long INF = 1LL<<60;


int main() {
  int64_t N,X,M,countf=0,countr=0,RT=0,FT=0,ans=0;
  cin>>N>>X>>M;
  auto XX=X;
  queue<int64_t> R,F;
  vector<int64_t> C(M,0);
  while(true){
    if(C[X]==0){
      countf++;
      C[X]++;
    }
    else if(C[X]==1){
      R.push(X);
      C[X]++;
      RT+=X;
      countr++;
    }
    else if(C[X]==2){
      break;
    }
    X=(X*X)%M;
  }
  countf-=countr;
  rep(i,countf){
    FT+=XX;
    F.push(XX);
    XX=(XX*XX)%M;
  }
  if(N<=countf){
    rep(i,N){
      auto t=F.front();
      F.pop();
      ans+=t;
    }
  }
  else{
    N-=countf;
    auto rc=N/countr, a=N%countr;
    ans+=FT+RT*rc;
    rep(i,a){
      auto t=R.front();
      R.pop();
      ans+=t;
    }
  }
  cout<<ans;
}


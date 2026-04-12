#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;


int main() {
  int64_t N,t=0; cin>>N;
  vector<int64_t> S(N);
  rep(i,N){
    cin>>S.at(i);
    t+=S.at(i);
    t%=MOD;
  }
  int64_t ans=0;
  rep(i,N){
    t=(t-S.at(i)+MOD)%MOD;
    ans+=S.at(i)*t;
    ans%=MOD;
  }
  cout<<ans;
}

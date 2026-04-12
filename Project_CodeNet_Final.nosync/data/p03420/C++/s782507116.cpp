#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

int main() {
  int64_t N,K;
  cin>>N>>K;
  int64_t ans=0;
  for(int b=1;b<=N;b++){
    ans+=(N+1)/b*max((int64_t)0,b-K);
    ans+=max((int64_t)0,(N+1)%b-K);
  }
  if(K==0){ans-=N;}
  cout<<ans<<endl;
  return 0;
}
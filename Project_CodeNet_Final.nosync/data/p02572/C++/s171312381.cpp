#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    sum+=A[i];
    sum%=mod;
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    sum-=A[i];
    if(sum<A[i]){sum+=mod;}
    ans+=(A[i]*sum);
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;  
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, n) ;for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) ;for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF (922337203685477587+1)
#define sosuu 1000000007

int main() {
  lli N;
  cin >> N;
  vector<lli> A(N);
  vector<lli> B(N-1);
  lli ans=0;
  rep(i, N) {
    cin >> A[i];
    A[i]%=sosuu;
    }
  rep(i, N-1)
  {
    if(i!=0)
  B[N-(i+1)-1]=(A[N-(i+1)]+B[N-(i+1)])%sosuu;
    
    else
      B[N-2]=A[N-1];
  }
    rep(i, N-1){
    ans+=A[i]*B[i];
      ans%=sosuu;
    
    
    
    }
  cout << ans << endl;
}
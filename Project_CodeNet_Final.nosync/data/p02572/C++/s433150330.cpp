#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main() {
  int N;
  long long Ans=0;
  
  cin>>N;
  vector<long long> A(N),Sum(N);
  
  rep(i,N){cin >> A.at(i);
           Sum.at(i)=A.at(i);
          }
  rep(i,N-1){Sum.at(N-i-2)=(Sum.at(N-i-2)+Sum.at(N-i-1))%MOD;}

  rep(i,N-1){Ans=(Ans+A.at(i)*Sum.at(i+1))%MOD;}

  cout<<Ans<<endl;

}
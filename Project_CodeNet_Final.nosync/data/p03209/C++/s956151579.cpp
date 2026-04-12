#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<long long> P(55),ALL(55);

long long calc(long long N,long long X) {
  if(N == 0) return 1;
  else if(X == 0) return 0;
  else if(1 < X && X < ALL.at(N-1)+2) return calc(N-1,X-1);
  else if(X == ALL.at(N-1)+2) return P.at(N-1)+1;
  else if(ALL.at(N-1)+2 < X && X < 2*ALL.at(N-1)+3) return P.at(N-1)+1+calc(N-1,X-2-ALL.at(N-1));
  else if(X == 2*ALL.at(N-1)+3) return 2*P.at(N-1)+1;
}

int main() {

  long long N,X;
  cin >> N >> X;

  
  P.at(0) = 1; ALL.at(0) = 1;
  for(int i = 1;i <= N;i++) {
    P.at(i) = 2*P.at(i-1) + 1;
    ALL.at(i) = 2*ALL.at(i-1) + 3;
  }

  long long ans = calc(N,X);
  cout << ans << endl;
}

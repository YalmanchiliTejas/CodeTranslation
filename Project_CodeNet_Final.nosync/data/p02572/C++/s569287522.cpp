#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i=0 ; i<N ; i++)
    cin >> A.at(i);
  
  vector<long long> S(N);
  S.at(N-1) = 0;
  for (int i=0 ; i<N-1 ; i++)
    S.at(N-2-i) = (S.at(N-1-i)+A.at(N-1-i))%1000000007;
  
  long long ans = 0, plus;
  for (int i=0 ; i<N-1 ; i++){
    plus = (A.at(i)*S.at(i))%1000000007;
    ans = (ans+plus)%1000000007;
  }
  cout << ans << endl;
}
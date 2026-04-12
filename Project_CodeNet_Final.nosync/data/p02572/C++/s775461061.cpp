#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  ll ans = 0, sum = A.at(N - 1);
  for (int i = N - 2; i >= 0; i--){
    ans += A.at(i) * sum;
    //cout << ans << endl;
    ans %= 1000000007;
    sum += A.at(i);
    sum %= 1000000007;
  }
  
  //cout << A.at(0) << endl;
  cout << ans << endl;
}
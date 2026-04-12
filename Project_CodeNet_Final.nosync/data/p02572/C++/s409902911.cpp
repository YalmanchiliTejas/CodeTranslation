#include <bits/stdc++.h>
using namespace std;

int main() {
  long Mod = 1000000007;
  int N;
  cin >> N;
  vector<long> A(N);

  for(int i = 0; i < N; ++i){
    cin >> A.at(i);
  }

  long sumA = 0;
  for(int i = 0; i < N; ++i){
    sumA += A.at(i);
  }

  long sum = 0;
  for(int i = 0; i < N-1; ++i){
    sumA -= A.at(i);
    long t = sumA % Mod;
    sum += A.at(i) * t;
    sum %= Mod;        
  }

  cout << sum << endl;
}

#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  vector<long long> V(N);
  for(int i = 0; i < N; i++){
  	cin >> V.at(i);
  }
  long long C = 1000000007;
  long long Sum = 0;
  vector<long long> W(N-1);
  W.at(0) = V.at(0);
  for(int i = 1; i < N-1; i++){
    W.at(i) = W.at(i-1) + V.at(i);
  }
  for(int i = 0; i < N-1; i++){
  	Sum += ((W.at(i)%C) * V.at(i+1)) % C;
  }
  cout << Sum % C<< endl;
}
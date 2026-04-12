#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int counter = 0;
  int ma = -1;
  for (int j = 0;j<N;j++){
    if(H[j]>=ma) {
      counter = counter + 1;
      ma = H[j];
    }
  }
  cout<<counter<<endl;
}
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  int N,max,mieru;
  vector<int> H(30);
  cin>>N;
  for (int i = 0; i < N; i++) cin>>H[i];
  max = H[0];
  mieru = 1;
  for (int i = 1; i < N; i++) {
    if (H[i] >= max) {
      mieru++;
      max = H[i];
    }
  }
  cout<<mieru<<endl;
  return 0;
}
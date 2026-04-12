#include "bits/stdc++.h"
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> r(N);
  for(int i = 0; i < N; i++)
  {
    cin >> r.at(i);
  }
  
  int count = 0;
  int high = 0;
  for(int i = 0; i < N; i++)
  {
    if (high <= r.at(i)) {
      count++;
      high = r.at(i);
    }
  }
  
  cout << count << endl;

  return 0;

}

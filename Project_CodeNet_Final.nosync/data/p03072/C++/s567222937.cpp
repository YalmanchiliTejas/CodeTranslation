#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  int count = 0;
  int maxv = 0;
  for(int i = 0; i < N; i++){
    maxv = max(maxv, H.at(i));
    if(maxv == H.at(i)){
      count++;
    }
  }
  cout << count << endl; 
}
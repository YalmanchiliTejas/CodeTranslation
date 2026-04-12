#include <bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  vector<int> H(25);
  
  for(int i=0; i<N; i++) cin >> H.at(i);
  int count =1;
  int maxim = H.at(0);
  for(int i=1; i<N; i++) {
    if(maxim <= H.at(i)) count++;
    maxim = max(maxim,H.at(i));
  }
  cout << count << endl;
}
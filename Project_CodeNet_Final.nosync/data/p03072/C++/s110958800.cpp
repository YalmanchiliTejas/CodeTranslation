#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int i=0;
  int b=0;
  int c=0;
  cin >> N;
  vector<int> B(N);
  for(i=0; i < N; ++i){
    cin >> B[i];
    if (b <= B[i]){
      b = B[i];
      c += 1;
    }
  }
  cout << c << endl;
}
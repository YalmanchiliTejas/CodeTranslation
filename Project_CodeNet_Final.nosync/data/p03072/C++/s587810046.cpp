#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  int H[N];
  for (int i=0; i<N; i++) cin >> H[i];
  
  int maxh = H[0];
  int count = 0;
  for (int i=0; i<N; i++) {
    if (maxh <= H[i]) {
      count++;
      maxh = max(maxh,H[i]);
    }
  }
  cout << count << endl;
}
#include <vector>
#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; ++i) cin >> H[i];
  int h = 0, ans = 0;
  for(int i = 0; i < N; ++i){
    if(H[i] >= h) ++ans, h = H[i];
  }
  cout << ans << endl;
}

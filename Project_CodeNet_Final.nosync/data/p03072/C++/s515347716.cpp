#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N; cin >>N;
  vector<int> H(N);
  for (int i=0; i<N;++i)cin >> H[i];
  
  int ans =0;
  int current_max =0;
  for (int i =0;i<N;++i){
    if (H[i]>=current_max)++ans;
    if (current_max<H[i])current_max=H[i];
  }
  cout <<ans <<endl;
}
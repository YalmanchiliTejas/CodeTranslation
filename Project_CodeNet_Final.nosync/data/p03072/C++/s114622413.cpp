#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int h[N];
  for (int i=0;i<N;i++) cin >> h[i];
  int count = 0;
  int h_max = h[0];
  for (int i=0;i<N;i++){
    if (h[i] >= h_max) count += 1;
    h_max = max(h_max,h[i]);
  }

  cout << count << endl;

  return 0;
}

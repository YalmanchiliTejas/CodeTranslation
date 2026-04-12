#include <iostream>
using namespace std;

int main() {
  int N, res=0, tmp_max=0;
  cin >> N;
  int H;

  for (int i=0; i<N; i++) {
    cin >> H;
    if(tmp_max<=H) {
      res++;
      tmp_max = H;
    }
  }
  cout << res;
}


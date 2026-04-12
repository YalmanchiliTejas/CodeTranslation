#include <iostream>

using namespace std;

int main() {
  int N = 0;
  cin >> N;
  int Hmax = 0; 
  int H = 0;
  int count = 0;
  for(int i=0;i<N;i++) {
    cin >> H;
    if (H >= Hmax) {
      	count++;
      	Hmax = H;
    }
  }
  cout << count;
  return 0;
}

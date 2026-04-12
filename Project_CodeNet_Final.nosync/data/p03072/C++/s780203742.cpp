#include <iostream>
#include <string>
using namespace std;


int main() {
  int N;
  int H[21];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int max = 0;
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(max <= H[i]) {
      count++;
      max = H[i];
    }
  }

  cout << count << endl;

  return 0;
}


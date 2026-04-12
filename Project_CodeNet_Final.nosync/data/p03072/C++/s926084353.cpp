#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int hmax, num = 0;
  int tmp;
  
  for(int i=0; i<N; i++) {
    cin >> tmp;
    if (hmax<=tmp) {
      hmax = tmp;
      num++;
    }
  }
  cout << num << endl;
}
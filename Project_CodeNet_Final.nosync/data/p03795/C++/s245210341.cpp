#include <iostream>

using namespace std;

int main(void){
  int N;
  cin >> N;

  int y = 800 * N;
  int x = 200 * (N/15);

  cout << y-x << endl;
  
  return 0;
}

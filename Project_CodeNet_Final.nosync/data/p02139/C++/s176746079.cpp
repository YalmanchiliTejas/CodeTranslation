#include <iostream>

using namespace std;

int main()
{
  int N, Q;
  int op, k;
  int index = 0;
  
  cin >> N >> Q;
  while (Q--) {
    cin >> op >> k;
    if (op == 0) {
      int element = (index + k) % N;
      element ? cout << element << endl : cout << N << endl;
    } else if (op == 1) {
      index = (index + k) % N;
    }
  }
}


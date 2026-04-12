#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  	if (N < 15) {
      cout << N * 800 << endl;
    }
  	else {
      cout << N * 800 - (N / 15 * 200) << endl;
    }
}
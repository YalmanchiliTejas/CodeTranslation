#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i, N) for (int i=0; i<(int)N; i++)

using namespace std;

int main() {
  string str_;
  cin >> str_;
  if (str_ == "AAA" || str_ == "BBB") {
    cout << "No";
  } else {
    cout << "Yes";
  }
}
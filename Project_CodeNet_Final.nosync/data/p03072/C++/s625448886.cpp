#include <iostream>
#include <string>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

int main() {
  int N, count=0;
  cin >> N;
  vector<int>H(N);
  for (int i = 0; i < N; i++) {cin >> H.at(i);}
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    A.at(i) = 0;
    for (int j = 0; j < i; j++) {
      if (H.at(i)<H.at(j)) {
        A.at(i)++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (A.at(i)==0) {
      count++;
    }
  }
  cout << count;
}
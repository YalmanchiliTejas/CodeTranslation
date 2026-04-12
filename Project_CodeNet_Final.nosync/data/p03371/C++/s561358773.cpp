#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B, AB, X, Y;
  cin >> A >> B >> AB >> X >> Y;
  int answer = A * X + B * Y;
  int temp = AB * max(X, Y) * 2;
  answer = min(answer, temp);
  temp = AB * min(X, Y) * 2;
  if (max(X, Y) == X) {
    temp += A * (X - Y);
  } else {
    temp += B * (Y - X);
  }
  answer = min(answer, temp);

  cout << answer << endl;
  return 0;
}
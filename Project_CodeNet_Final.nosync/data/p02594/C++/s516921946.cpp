#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
const double PI = 3.14159265358979323846;
int vector_finder(vector<int> vec, int number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance(vec.begin(), itr);
  if (index != vec.size()) {  // 発見できたとき
    return 1;
  } else {  // 発見できなかったとき
    return 0;
  }
}
int main() {
  int n;
  cin >> n;
  if (n >= 30)
    cout << "Yes";
  else
    cout << "No";

  return 0;
}
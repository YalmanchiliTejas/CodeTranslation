#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 100101;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  cout << (n == 7 || n == 5 || n == 3 ? "YES": "NO") << endl;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> v{3, 5, 7};
  cout << (find(v.begin(), v.end(), n) != v.end() ? "YES" : "NO") << endl;
  return 0;
}
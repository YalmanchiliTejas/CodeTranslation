#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main(void) {
  int n; cin >> n;
  unordered_map<char,int> counter[51];
  for (int i = 0; i < 51; i++)
    for (char c = 'a'; c <= 'z'; c++)
      counter[i][c] = 0;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (char c : s) { counter[i][c]++; }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    vector<int> cvec(n);
    for (int i = 0; i < n; i++) { cvec[i] = counter[i][c]; }
    std::sort(cvec.begin(), cvec.end());
    for (int k = 0; k < cvec[0]; k++)
      cout << c;
  }
  cout << endl;
}

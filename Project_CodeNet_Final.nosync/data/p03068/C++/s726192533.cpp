#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int k, n;
  // char mt;
  // vector<char> m;

  string s;
  cin >> n;
  // for (int i = 0; i < n; ++i) {
  //   cin >> mt;
  //   m.push_back(mt);
  // }
  cin >> s;
  cin >> k;

  char moji = s[k-1];

  string out;
  for (auto c : s){
    if(c == moji)
      out.push_back(c);
    else
      out.push_back('*');
  }
  cout << out <<endl;
  // for (auto l : s) {
  //   cout << l << endl;
  // }

  // int minn = *min_element(p.begin(), p.end());
  // cout << minn << endl;
}

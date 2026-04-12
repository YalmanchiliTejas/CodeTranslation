#include <iostream>
using namespace std;

int main()
{
  int n, k;
  string s;
  cin >> n >> s >> k;
  for (auto&& e : s) {
    cout << (e == s[k - 1] ? e : '*');
  }
  cout << endl;
}

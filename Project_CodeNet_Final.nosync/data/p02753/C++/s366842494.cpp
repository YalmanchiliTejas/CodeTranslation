#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  cout << (s[0] != s[2] ? "Yes" : "No") << endl;
  return 0;
}

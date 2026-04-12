#include <algorithm>
#include <climits>
#include <iostream>
#include <iomanip>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::lower_bound;
using std::upper_bound;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;
  cout << ((s[0] != s[1] || s[0] != s[2]) ? "Yes" : "No");
  return 0;
}

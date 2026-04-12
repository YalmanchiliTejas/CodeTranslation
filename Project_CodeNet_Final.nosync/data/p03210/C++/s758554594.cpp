#include <algorithm>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;


class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    if (n == 3 || n == 5 || n == 7)
      out << "YES\n";
    else out << "NO\n";
  }
};

void solve(std::istream& in, std::ostream& out)
{
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
// Powered by caide (code generator, tester, and library code inliner)


#include <fstream>
#include <iostream>


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  istream& in = cin;


  ostream& out = cout;

  solve(in, out);
  return 0;
}


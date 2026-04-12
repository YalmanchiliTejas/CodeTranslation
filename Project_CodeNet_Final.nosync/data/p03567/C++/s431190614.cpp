#include <bits/stdc++.h>


using namespace std;


// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
  void solve(std::istream& in, std::ostream& out)
  {
    string str;
    in >> str;
    auto i = str.find("AC");
    if(i != string::npos) {
      out << "Yes\n";
    } else {
      out << "No\n";
    }
  }
};

void solve(std::istream& in, std::ostream& out)
{
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  istream& in = cin;


  ostream& out = cout;

  solve(in, out);
  return 0;
}



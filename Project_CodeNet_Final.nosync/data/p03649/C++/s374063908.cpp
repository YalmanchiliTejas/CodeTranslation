#include <bits/stdc++.h>


using namespace std;


// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
  void solve(std::istream& in, std::ostream& out)
  {
    int n;
    in >> n;
    vector<long long> a(n);
    for(auto&& i : a) {
      in >> i;
    }
    long long ans = 0;
    while (true) {
      sort(a.rbegin(), a.rend());
      if(a[0] < n) {
        break;
      }
      vector<long long> score(n);
      for (int i = 0; i < n; i++) {
        long long add = a[i] / n;
        a[i] %= n;
        score[i] += a[i];
        for (int j = 0; j < n; j++) {
          if(i == j) {
            continue;
          }
          score[j] += add;
        }
        ans += add;
      }
      a = score;
    }
    out << ans << "\n";
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



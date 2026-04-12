#include <bits/stdc++.h>
using namespace std;
#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL);

int main() {
  FAST;
  string S;
  cin >> S;
  string result;
  if (S.at(0) == S.at(1) && S.at(1) == S.at(2)) {
    result = "No";
  }
  else {
    result = "Yes";
  }
  cout << result << endl;
}
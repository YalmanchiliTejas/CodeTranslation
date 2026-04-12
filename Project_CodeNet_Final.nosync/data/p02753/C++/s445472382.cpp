#include<iostream>
#include<string>

using namespace std;

int main (void) {
  string str;
  cin >> str;
  bool haveA = false;
  bool haveB = false;
  for (auto& c : str) {
    if (c == 'A') haveA = true;
    if (c == 'B') haveB = true;
  }
  auto res = haveA&&haveB ? "Yes" : "No";
  cout << res;
}
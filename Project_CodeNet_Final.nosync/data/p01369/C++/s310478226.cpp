// AOJ 2252
#include<iostream>
#include<string>
using namespace std;

bool member(char c, string set) {
  for (auto&& x : set) {
    if (c == x) return true;
  }
  return false;
}

int solve(string str) {
  int ans = 0;
  string left = "qwertasdfgzxcvb", // false
         right = "yuiophjklnm"; // true
  bool hand = member(str[0],right);
  for (auto&& c : str) {
    string current = (hand ? right : left);
    if (!member(c, current)) {
      hand = !hand;
      ans++;
    }
  }
  return ans;
}

int main() {
  string query;
  while (cin >> query and query != "#") {
    cout << solve(query) << endl;
  }
}
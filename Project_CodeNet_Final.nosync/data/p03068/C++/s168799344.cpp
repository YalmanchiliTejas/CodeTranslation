// Created by martinezdiego on 23/4/19

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> s >> k;
  for (auto i : s) {
    if (i == s[k-1])
      cout << i;
    else
      cout << '*';
  }
  cout << '\n';
  return 0;
}
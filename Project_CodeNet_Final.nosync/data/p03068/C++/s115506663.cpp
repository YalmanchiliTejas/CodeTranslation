#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  string s;
  cin >> N >> s >> K;
  char c = s[K-1];
  for (auto a : s) {
    if (a == c) cout << a;
    else cout << '*';
  }
  cout << endl;
}
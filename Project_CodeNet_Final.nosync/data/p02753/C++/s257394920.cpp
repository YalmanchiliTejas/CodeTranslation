#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

  string S;
  cin >> S;
  int count[2] = {0, 0};
  for (auto c: S) count[c-'A']++;
  if (count[0] && count[1]) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}


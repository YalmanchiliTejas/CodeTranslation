#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  string str; cin >> str;
  bool ok = false;
  for (int i = 0; i + 1 < str.size(); ++i) {
	if (str.substr(i, 2) == "AC") ok = true;
  }
  if (ok) puts("Yes");
  else puts("No");
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  	string s = "";
  	for (int i = 0; i < 3; i++) {
    	char a;
      	cin >> a;
      	s += a;
    }
  	int foo = stoi(s);
  	cout << (foo % 4 == 0 ? "YES" : "NO") << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	char a, b, c;
  	cin >> a >> b >> c;
  bool hasa = false;
  bool hasb = false;
  if (a == 'A' || b == 'A' || c == 'A') hasa = true;
  if (a == 'B' || b == 'B' || c == 'B') hasb = true;
  
  if (hasa && hasb) cout << "Yes" << endl;
  else cout << "No" << endl;
}
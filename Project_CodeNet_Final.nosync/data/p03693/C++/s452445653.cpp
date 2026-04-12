#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
	int a, b, c;
  cin >> a >> b >> c;
  int sum = a * 100 + b * 10 + c;
  if (sum % 4) cout << "NO" << endl;
  else cout << "YES" << endl;
	return 0;
}

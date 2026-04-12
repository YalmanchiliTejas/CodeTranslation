#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int R, G, B; cin >> R >> G >> B;
	if ((G * 10 + B) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
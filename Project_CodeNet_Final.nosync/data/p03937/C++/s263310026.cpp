#include <iostream>
using namespace std;
int main() {
	int h, w, cnt = 0;
	char c;
	cin >> h >> w;
	while (cin >> c)cnt += c == '#';
	cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
}

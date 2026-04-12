#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int r,g,b;
	cin >> r >> g >> b;
	string s = to_string(r) + to_string(g) + to_string(b);
	if(stoi(s) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
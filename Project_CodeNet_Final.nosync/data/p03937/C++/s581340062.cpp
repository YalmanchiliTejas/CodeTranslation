#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W;
	int cnt = 0;
	cin >> H >> W;
	for(int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++) cnt += s[j] == '#';
	}
	if(cnt == H+W-1)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
}

#include <iostream>
#include<string>
using namespace std;
char s[19][19];
int main() {
	int h, w;
	int cnt = 0;
	cin >> h >> w;
	for(int i=0;i<h;i++){
		for (int j =0 ; j < w; j++) {
			cin >> s[i][j];
			if (s[i][j] == '#') { cnt++; }
	}
	}
	if (cnt == h + w - 1) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }
}

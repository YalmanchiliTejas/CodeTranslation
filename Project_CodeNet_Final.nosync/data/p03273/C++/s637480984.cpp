#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,W;
	cin >> H >> W;
	string map[H];
	for(int i=0; i<H; i++) cin >> map[i];

	vector<bool> row(H,false), col(W,false);

	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			if(map[i][j]=='#') {
				row[i] = true;
				col[j] = true;
			}

	for(int i=0; i<H; i++) {
		if(row[i]) {
			for(int j=0; j<W; j++) {
				if(col[j])
					cout << map[i][j];
			}
		cout << endl;
		}
	}
}

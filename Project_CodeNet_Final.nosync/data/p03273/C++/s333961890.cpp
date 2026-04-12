#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for(int i=0; i<h; i++) cin >> a[i];
    
        // 各行と各列に'#'があるかどうか調べる
	vector<bool> row(h, false);
	vector<bool> col(w, false);
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j] == '#'){
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for(int i=0; i<h; i++){
		if(row[i]){  // その行に'#'があれば
			for(int j=0; j<w; j++){
				if(col[j]){  // その列に'#'があれば
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}
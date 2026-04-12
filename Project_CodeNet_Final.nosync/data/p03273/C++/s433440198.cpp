#include <bits/stdc++.h>
using namespace std;

int main() {

	int h, w;
	cin >> h >> w;

	vector<vector<char>> data(h, vector<char>(w));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> data.at(i).at(j);
		}
	}

	vector<int> row(h);
	vector<int> column(w);

	//row
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(data.at(i).at(j) == '#') break;
			if(j == w-1) row.at(i) = 1;
		}
	}
	//column
	for(int j=0; j<w; j++){
		for(int i=0; i<h; i++){
			if(data.at(i).at(j) == '#') break;
			if(i == h-1) column.at(j) = 1;
		}
	}

	//print
	for(int i=0; i<h; i++){
		if(row.at(i) == 1) continue;
		for(int j=0; j<w; j++){
			if(column.at(j) == 1) continue;
			cout << data.at(i).at(j);
		}
		cout << endl;
	}
 
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int h, w;
	cin >> h >> w;
	
	vector<vector<char>> a(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a.at(i).at(j);
		}
	}

	for (int i = 0; i <a.size() ; i++) {
		bool hasBlack = false;
		for (int j = 0; j < w; j++) {
			if (a.at(i).at(j) == '#') {
				hasBlack = true;
				break;
			}
		}
		if (!hasBlack) {
			a.erase(a.begin() + i);
			i--;
		}
	}

	for (int j = 0; j < a.at(0).size(); j++) {
		bool hasBlack = false;
		for (int i = 0; i < a.size(); i++) {
			if (a.at(i).at(j) == '#') {
				hasBlack = true;
				break;
			}
		}
		if (!hasBlack) {
			for (int i = 0; i < a.size(); i++) {
				a.at(i).erase(a.at(i).begin() + j);
			}
			j--;
		}
	}


	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(i).size(); j++) {
			cout << a.at(i).at(j);
		}
		cout << endl;
	}


}
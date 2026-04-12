#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {

	int H, W, xkey, ykey;
	cin >> H >> W;
	vector<string> S(H);

	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}

	int i = 0;

	while (i != S.size()) {
		xkey = 0;
		for (int j = 0; j < S[0].size(); j ++) {
			if (S[i][j] == '.') {
				xkey++;
			}
		}
		if (xkey == S[0].size()) {
			S.erase(S.begin() + i);
		}
		else {
			i++;
		}
	}
	
	int j = 0;

	while (j != S[0].size()) {
		ykey = 0;
		for (int i = 0; i < S.size(); i++) {
			if (S[i][j] == '.') {
				ykey++;
			}
		}
		if (ykey == S.size()) {
			for (int i = 0; i < S.size(); i++) {
				S[i].erase(j, 1);
			}
		}
		else {
			j++;
		}
	}


	for (int i = 0; i < S.size(); i++) {
		cout << S[i] << "\n";
	}


	return 0;
}

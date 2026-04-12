#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void inputVector(int n, vector<char>& va) {
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		va.push_back(a);
	}
}
void inputMatrix(int h, int w, vector<vector<char>>& ma) {
	for (int i = 0; i < h; i++) {
		vector<char> va;
		inputVector(w, va);
		ma.push_back(va);
	}
}

void checkRow(int&h, int i, int w, vector<vector<char>>& ma) {
	for (int j = 0; j < w; j++) {
		if (ma.at(i).at(j) == '#') return;
	}
	ma.erase(ma.begin() + i);
	h--;
}

void checkColumn(int h, int& w, int j, vector<vector<char>>& ma) {
	for (int i = 0; i < h; i++) {
		if (ma.at(i).at(j) == '#') return;
	}
	for (int i = 0; i < h; i++) {
		ma.at(i).erase(ma.at(i).begin() + j);
	}
	w--;
}

void outputVector(int n, vector<char> va) {
	for (int i = 0; i < n; i++) {
		cout << va.at(i);
	}
	cout << "\n";
}

void outputMatrix(int h, int w, vector<vector<char>> ma) {
	for (int i = 0; i < h; i++) {
		outputVector(w, ma.at(i));
	}
}

int main(void)
{
	int h, w;
	cin >> h >> w;
	vector<vector<char>> ma;
	inputMatrix(h, w, ma);

	for (int i = h - 1; i >= 0; i--) {
		checkRow(h, i, w, ma);
	}
	for (int j = w - 1; j >= 0; j--) {
		checkColumn(h, w, j, ma);
	}

	outputMatrix(h, w, ma);
	return 0;
}
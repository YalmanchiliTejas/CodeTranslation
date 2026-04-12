#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<tuple>

//AtCoderC++.cpp

using namespace std;

template<typename T> void Show(const vector<vector<T>>& v, string delimiter = " ") {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
			if (j != v[i].size() - 1) {
				cout << delimiter;
			} else {
				cout << endl;
			}
		}
	}
}
template<typename T> void Show(const vector<T>& v, string delimiter = " ") {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) {
			cout << delimiter;
		} else {
			cout << endl;
		}
	}
}
template<typename T> vector<T> getUniform(T value, int n) {
	vector<vector<T>> ts;
	ts.resize(n);
	for (int i = 0; i < n; i++) {
		ts[i] = value;
	}
	return ts;
}
template<typename T> vector<vector<T>> getUniform(T value, int row, int col) {
	vector<vector<T>> ts;
	ts.resize(row);
	for (int i = 0; i < row; i++) {
		ts[i].resize(col);
		for (int j = 0; j < col; j++) {
			ts[i][j] = value;
		}
	}
	return ts;
}
bool All(vector<vector<bool>> ts) {
	int h = ts.size();
	int w = ts[0].size();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (!ts[i][j])return false;
	return true;
}

vector<string> split(string& content, char delim) {
	auto ss = vector<string>();
	string s = "";
	for (size_t i = 0; i < content.length(); i++) {
		if (content[i] == delim) {
			ss.push_back(s);
			s = "";
			continue;
		}
		s += content[i];
	}
	if (s != "")ss.push_back(s);
	return ss;
}

int main() {
	int N; cin >> N;
	auto hs = vector<int>(N);
	for (size_t i = 0; i < N; i++)cin >> hs[i];
	int max = hs[0]; 
	int count = 0;
	for (size_t i = 0; i < N; i++) {
		if (max <= hs[i]) {
			count++;
			max = hs[i];
		}
	}
	cout << count << endl;
}


#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<int>>A(N, vector<int>(26, 0));
	string S;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			A.at(i).at(S.at(j) - 97)++;
		}
	}
	vector<int>ans(26);
	for (int i = 0; i < 26; i++) {
		int MIN = 3000;
		for (int j = 0; j < N; j++) {
			if (A.at(j).at(i) < MIN) MIN = A.at(j).at(i);
		}
		ans.at(i) = MIN;
	}
	string T;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < ans.at(i); j++) {
			T.push_back('a' + i);
		}
	}
	cout << T << endl;
}

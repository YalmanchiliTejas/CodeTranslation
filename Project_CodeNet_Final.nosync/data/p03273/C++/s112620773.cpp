#include "bits/stdc++.h"
using namespace std;
typedef pair<long long, long long> P;
int main() {
	long long N, M; cin >> N >> M;
	vector<vector<char>>A(N, vector<char>(M));
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < M; j++) {
			cin >> A.at(i).at(j);
		}
	}
	vector<long long>line;
	for (long long i = 0; i < N; i++) {
		bool check = true;
		for (long long j = 0; j < M; j++) {
			if (A.at(i).at(j) != '.') check = false;
		}
		if (check)line.push_back(i);
	}
	vector<long long>low;
	for (long long i = 0; i < M; i++) {
		bool check = true;
		for (long long j = 0; j < N; j++) {
			if (A.at(j).at(i) != '.') check = false;
		}
		if (check) low.push_back(i);
	}
	long long k = 0;
	for (long long i = 0; i < N; i++) {
		if (!line.empty() && k < line.size()) {
			if (line.at(k) == i) {
				k++;
				continue;
			}
		}
		long long l = 0;
		for (long long j = 0; j < M; j++) {
			if (!low.empty() && l < low.size()) {
				if (low.at(l) == j) {
					l++;
					continue;
				}
			}
			cout << A.at(i).at(j);
		}
		cout << endl;
	}
}
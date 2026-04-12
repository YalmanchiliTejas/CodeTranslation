#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"
string to_string_keta(const long long int l, const int keta) {
	ostringstream oss;

	oss << std::setw(keta) << std::setfill(' ') << l;

	return oss.str();
}

int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		vector<vector<int>>vs(N,vector<int>(N));
		int nx = N / 2-1;
		int ny = N / 2;
		for (int num = 1; num <= N*N; ++num) {
			nx += 1;
			ny += 1;
			nx %= N;
			ny %= N;
			while (1) {
				if (vs[ny][nx]) {

					nx += N - 1;
					ny += 1;
					nx %= N;
					ny %= N;
				}
				else {
					vs[ny][nx]=num;
					break;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << to_string_keta(vs[i][j], 4);
				if (j == N - 1)cout << endl;
				
			}
		}
	}
	return 0;
}
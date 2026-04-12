#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#include<cstdio>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORq(i, m, n) for(int i = (m); i < (n); i++)
#define FORr(i, n) for (int i = (n); i >= 0; i++)


int main() {
	int N, K;
	string S;

	cin >> N;
	cin >> S;
	cin >> K;

	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}
	cout << S << endl;
}
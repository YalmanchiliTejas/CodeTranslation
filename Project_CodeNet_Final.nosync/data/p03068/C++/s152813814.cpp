#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int N; cin >> N;
	char S[10];
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int K; cin >> K;
	K = K - 1;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K]) {
			S[i] = '*';
		}
		cout << S[i];
	}
}
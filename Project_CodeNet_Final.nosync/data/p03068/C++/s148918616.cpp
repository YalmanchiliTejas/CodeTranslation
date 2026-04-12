#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	int N;//文字数
	string S;//文字列
	int K;//場所
	char s;

	cin >> N;
	cin >> S;
	cin >> K;

	s = S[K - 1];//変える文字

	for (int i = 0; i < N; i++) {
		if (S[i] != s) {
			S[i] = '*';
		}
	}

	cout << S << endl;


}


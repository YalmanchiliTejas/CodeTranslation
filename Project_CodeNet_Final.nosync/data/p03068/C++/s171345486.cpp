#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int size = S.size();
	int K;
	cin >> K;
	for (int i = 0; i < size; i++) {
		if (S[i] != S[K - 1]) { S[i] = '*'; }
	}
	cout << S << endl;
}
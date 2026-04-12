#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
using namespace std;
#define lol long long


int main()
{
	int N, K;
	string S;
	cin >> N >> S >> K;
	for (int i = 0; i < N; i++) {
		if (S[K - 1] != S[i]) {
			S[i] = '*';
		}
	}
	cout << S << endl;
}
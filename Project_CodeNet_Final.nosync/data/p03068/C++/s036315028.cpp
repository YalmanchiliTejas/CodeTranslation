#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

//typedefリスト
typedef long long llint;
typedef vector<long long int> vint;
typedef vector< vector<int> > vvint;
typedef vector<string> vstr;


int main(void) {
	int N, K;
	string S;
	cin >> N >> S >> K;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1])S[i] = '*';
	}
	cout << S << endl;
}

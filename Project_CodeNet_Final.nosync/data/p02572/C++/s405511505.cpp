//============================================================================
// Name        : AOJ_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	unsigned long long int N;
	vector<unsigned long long int> Ai;
	cin >> N;
	Ai.resize(N);
	for (unsigned int i = 0; i < N; i++) {
	    cin >> Ai[i];
	}

    unsigned long long int answer = 0;
    unsigned long long int mulans = 0;
    unsigned long long int mulbase = 0;

	for (unsigned int i = 0; i < N - 1; i++) {
		mulbase = (mulbase + Ai[N-1-i]) % 1000000007;
	    mulans = (mulbase * Ai[N-2-i]) % 1000000007;
	    answer = (answer + mulans) % 1000000007;
	}

    cout << answer << endl;
	// cout << tlen - max << endl;
	return 0;
}

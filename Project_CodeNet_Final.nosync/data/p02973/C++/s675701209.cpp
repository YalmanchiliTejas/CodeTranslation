#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;


int main() {
	int N; cin >> N;
	vector<long long> A(N), B;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	B.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		auto itr = lower_bound(B.rbegin(), B.rend(), A[i]);
		if (itr == B.rbegin())B.emplace_back(A[i]);
		else { itr--; *itr = A[i]; }
		
	}
	
	cout << B.size() << endl;
}




#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <map>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
		cin >> H.at(i);
	
	int ans = 1, joi = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (H.at(j) <= H.at(i)) joi++;
		}
		if (joi == i) ans++;
		joi = 0;
	}
	
	cout << ans << endl;
}
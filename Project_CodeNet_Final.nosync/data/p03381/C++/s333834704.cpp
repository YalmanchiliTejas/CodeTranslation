#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

long long N,a,b;
long long A;
long long B;
long long C[200001] = {};
long long result=0;
string S,SN,bufS;
vector <long long>vl;
vector <long> v;
//typedef pair<long long, long long> pl;



int main() {

	cin >>N;

	for (int i = 0; i < N; i++) {
		cin >> C[i];
		v.push_back(C[i]);
	}

	sort(v.begin(), v.end());
	A = v[(N / 2)-1];
	B = v[(N / 2)];

	for (int i = 0; i < N; i++) {
		if (A >= C[i]) {
			cout << B << endl;
		}
		else {
			cout << A << endl;
		}
	}

	

return 0;
}
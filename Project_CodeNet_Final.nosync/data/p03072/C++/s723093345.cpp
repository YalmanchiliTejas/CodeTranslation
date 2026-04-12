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
	int N,cou;
	cou = 1;
	cin >> N;
	vint H(N);
	for (int i = 0; i < N; i++)cin >> H[i];
	for (int i = 1; i < N; i++) {
		int jur = 0;
		for (int j = 0; j < i; j++) {
			if (H[j] > H[i])jur = 1;
		}
		if (jur == 0)cou++;
	}
	cout << cou << endl;
}

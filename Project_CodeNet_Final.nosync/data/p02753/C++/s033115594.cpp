#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

int a, b, c;
int N;
string s;

int main() {
	cin >> s;

	if (s == "AAA" || s == "BBB") {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	
	return 0;
}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main() {
	int n;
	int h[22];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int x = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (x <= h[i]) {
			x = h[i];
			count++;
		}
	}
	cout << count << endl;
}
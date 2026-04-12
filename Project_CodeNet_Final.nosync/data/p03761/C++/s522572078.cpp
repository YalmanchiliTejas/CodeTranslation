#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <stdio.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define ABS(a) ((a)>0 ? (a) : (a * -1))



int main(){
	int n, m;
	cin >> n;
	vs s(n);
	char buf, ans;
	int a[50][30];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 30; j++) {
			a[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			buf = s[i][j];
			a[i][buf-97]++;
		}
	}

	for (int i = 0; i < 30; i++) {
		m = 100;
		for (int j = 0; j < n; j++) {
			if ((m > a[j][i])) m = a[j][i];
		}
		if (m == 100) m = 0;

		for (int k = 0; k < m; k++) {
			ans = i + 97;
			cout << ans;
		}
	}

	cout << endl;

}

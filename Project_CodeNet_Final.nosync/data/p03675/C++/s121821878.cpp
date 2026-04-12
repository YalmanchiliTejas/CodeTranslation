#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007

using namespace std;

int main(void) {
	int n;
	

	cin >> n;
	vector<int>a(n + 1);
	FOR(i, 1, n) {
		cin >> a[i];
	}
	if (n % 2 == 0) {
		RFOR(i, n, 2) {
			cout << a[i] << " ";
			i--;
		}
		FOR(i, 1, n - 1) {
			if (i == n - 1) {
				cout << a[i] << endl;
			}
			else {
				cout << a[i] << " ";
			}
			i++;
		}
	}
	else {
		RFOR(i, n, 1) {
			cout << a[i] << " ";
			i--;
		}
		FOR(i, 2, n - 1) {
			if (i == n - 1) {
				cout << a[i] << endl;
			}
			else {
				cout << a[i] << " ";
			}
			i++;
		}
	}
	return 0;
}
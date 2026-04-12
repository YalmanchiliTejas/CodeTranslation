#include "bits/stdc++.h"

#define rep(a,b) for(int a = 0;a < n;a++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 1, -1 , 0 , 0 };
int dy[] = { 0,  0,  1, -1 };

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n = 10 * b + c;
	if (n % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 100005
using namespace std;

int n;
char a[N], b[N];

//void f(int p) {
//	if (p > n) {
//		if (b[n] == b[0]) {
//			b[n] = '\0';
//			cout << b << endl;
//			exit(0);
//		}
//		return;
//	}
//	if (a[p - 1] == 'o') {
//		if (b[p - 1] == 'S') b[p] = b[p - 2], f(p + 1);
//		else b[p] = (b[p - 2] == 'S' ? 'W' : 'S'), f(p + 1);
//	} else {
//		if (b[p - 1] == 'W') b[p] = b[p - 2], f(p + 1);
//		else b[p] = (b[p - 2] == 'S' ? 'W' : 'S'), f(p + 1);
//	}
//}

void f() {
	int i;
	for (i = 2; i <= n; i++) {
		if (a[i - 1] == 'o') {
			if (b[i - 1] == 'S') b[i] = b[i - 2];
			else b[i] = (b[i - 2] == 'S' ? 'W' : 'S');
		} else {
			if (b[i - 1] == 'W') b[i] = b[i - 2];
			else b[i] = (b[i - 2] == 'S' ? 'W' : 'S');
		}
	}
	if (b[n] == b[0]) {
		if (a[0] == 'o') {
			if (b[0] == 'S') b[n + 1] = b[n - 1];
			else b[n + 1] = (b[n - 1] == 'S' ? 'W' : 'S');
		} else {
			if (b[0] == 'W') b[n + 1] = b[n - 1];
			else b[n + 1] = (b[n - 1] == 'S' ? 'W' : 'S');
		}
		if (b[n + 1] == b[1]) {
			b[n] = '\0';
			cout << b << endl;
			exit(0);
		}
	}
}

int main()
{
	cin >> n >> a;
	b[0] = 'S'; b[1] = 'S'; f();
	b[0] = 'S'; b[1] = 'W'; f();
	b[0] = 'W'; b[1] = 'S'; f();
	b[0] = 'W'; b[1] = 'W'; f();
    cout << "-1" << endl;
    return 0;
}

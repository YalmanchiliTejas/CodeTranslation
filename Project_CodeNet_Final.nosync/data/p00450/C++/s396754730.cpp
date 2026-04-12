#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional> //sort(A,A.end(),greater<int>());???????????????
#include <queue>
#include <stack>
#include <vector>

#define INF 10 << 10
/*
int c[100001];
int go[100001];

int main() {
	int n;
	while (cin >> n && n != 0) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		go[0] = c[0];
		for (int i = 1; i < n; ++i) {
			if ((i + 1) % 2 == 0 && go[i - 1] != c[i]) {
				go[i - 1] = 1 - go[i - 1];
				int i2 = i - 2;
				while (i2 >= 0 && go[i - 1] == go[i2]) {
					go[i2] = 1 - go[i2];
					--i2;
				}
			}
			go[i] = c[i];
		}
		cout << endl << "****************" << endl;
		for (int i = 0; i < n; ++i) {
			cout << go[i];
			if (go[i] == 0) { ++cnt; }
		}
		cout << endl << "****************" << endl;
		cout << cnt << endl;
	}
*/
int c[100001];
int go[100001];
int main(){
	int n;
	while (cin >> n && n != 0) {
		for (int i = 1; i <= n; ++i) {
			cin >> c[i];
		}
		int right = 0;
		go[right] = 1;
		int left = c[1], prev = c[1];
		for (int i = 2; i <= n; ++i) {
			if (prev == c[i]) { ++go[right]; }
			else if (i % 2 == 0) {
				if (right == 0) {
					++go[right];
					left = c[i];
				}
				else {
					go[right - 1] += go[right] + 1;
					--right;
				}
			}
			else {
				++right;
				go[right] = 1;
			}
			prev = c[i];
		}
		int sum = 0;
		int num = 0;
		for (int i = 0; i <= n && num < n && sum < n; ++i) {
			num += go[i];
			if (left == 0) {
				if (i % 2 == 0) {
					sum += go[i];
				}
			}
			else {
				if (i % 2 == 1) {
					sum += go[i];
				}
			}
		}
		cout << sum << endl;
	}

	return 0;
}
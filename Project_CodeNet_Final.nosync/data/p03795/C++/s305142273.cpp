#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include<stack>
#include <unordered_map>

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int abs(int a) { return a < 0 ? -a : a; }

int combi(int n, int r) {
	int num = 1;
	for (int i = 1; i <= r; i++) {
		num = num * (n - i + 1) / i;
	}
	return num;
}
using namespace std;

int main() {
	int N;
	cin >> N;
	int x = N * 800;
	int y = (N / 15) * 200;
	cout << x - y;
	return 0;
}


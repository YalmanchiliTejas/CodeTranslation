#include<iostream>
using namespace std;
int main() {
	long long N, X, patty = 0;
	cin >> N >> X;
	for (long long i = (long long)(1 << (N >> 1) + 1) * (1 << (N >> 1) + (N & 1));i;i >>= 1, -- X) {
      	if (X + 1 >= i) {
			patty |= i >> 1;
			X -= i - 2;
		}
	}
	cout << patty;
	return 0;
}
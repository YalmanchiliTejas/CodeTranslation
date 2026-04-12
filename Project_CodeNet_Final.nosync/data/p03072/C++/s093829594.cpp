#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int MAX = 0, Ans = 0;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		if (H >= MAX) {
			Ans++;
			MAX = H;
		}
	}
	cout << Ans << endl;
}
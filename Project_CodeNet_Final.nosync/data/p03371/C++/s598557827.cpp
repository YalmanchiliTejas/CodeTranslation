#include<iostream>
#include<string.h>

using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int more = X >= Y ? X : Y;
	int ans = C * 200000;
	for (int i = 0; i <= more * 2; i += 2) {
		int tmp = 0;
		int num_A = X - i / 2;
		int num_B = Y - i / 2;
		tmp += C * i;
		if (num_A > 0)tmp += A * num_A;
		if (num_B > 0)tmp += B * num_B;
		if (tmp < ans)ans = tmp;
	}
	cout << ans << endl;
	return 0;
}
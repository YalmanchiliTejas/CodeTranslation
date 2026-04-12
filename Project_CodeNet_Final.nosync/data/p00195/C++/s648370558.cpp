#include<iostream>
using namespace std;
char A[6] = "ABCDE";
int a, b, maxn, maxid;
int main() {
	while (true) {
		maxn = 0;
		for (int i = 0; i < 5; i++) {
			cin >> a >> b;
			if (a == 0 && b == 0) { goto E; }
			if (maxn < a + b) {
				maxn = a + b;
				maxid = i;
			}
		}
		cout << A[maxid] << ' ' << maxn << endl;
	}
E:;
	return 0;
}
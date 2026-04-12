#include <iostream>
using namespace std;
int larger(int x,int y) {
	int z = 0;
	if (x > y)z = x;
	else z = y;
	return z;
}
int smaller(int x, int y) {
	int z = 0;
	if (x < y)z = x;
	else z = y;
	return z;
}
int main(void) {
	int s = 1;
	while (s == 1) {
		int sinsa, a[100], sum = 0, ave;
		cin >> sinsa;
		if (sinsa == 0)return 0;
		for (int i = 0; i < sinsa; i++) {
			cin >> a[i];
		}
		int n = a[0];
		for (int i = 0; i < sinsa; i++) {
			n = larger(n, a[i]);
		}
		int m = a[0];
		for (int i = 0; i < sinsa; i++) {
			m = smaller(m, a[i]);
		}
		for (int i = 0; i < sinsa; i++) {
			sum += a[i];
		}
		sum = sum - n - m;
		ave = sum / (sinsa - 2);
		cout << ave<<endl;
	}

	return 0;

}
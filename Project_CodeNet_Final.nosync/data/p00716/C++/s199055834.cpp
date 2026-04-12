#include <iostream>
using namespace std;

int main(void)
{
	int m, sikinA, years, n, p, A, C, max;
	double risi;
	cin >> m;
	for (int i = 0; i < m; i++) {
		max = 0;
		cin >> sikinA >> years >> n;
		for (int j = 0; j < n; j++) {
			cin >> p >> risi >> C;
			A = sikinA;
			if (p == 0) {
				int B = 0;
				for (int i = 0; i < years; i++) {
					B += (int)((double)A * risi);
					A = A - C;
				}
				A += B;
			}else {
				for (int i = 0; i < years; i++) {
					A = A + (int)((double)A * risi) - C;
				}
			}
			if (max < A) max = A;
		}
		cout << max << endl;
	}
	
	return 0;
}
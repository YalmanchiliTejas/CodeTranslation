#include <iostream>
#include <cstdio>
using namespace std;

int Hukuri(int y, int m, double n, int t) {
	// printf("hukuri,  %d, %d, %lf, %d\n", y, m, n, t);
	for (int i=0; i<y;i++) {
		m += m*n;
		m -= t;
	}
	// printf("\n Ans %d \n", m);
	return m;
}

int Tanri(int y, int m, double n, int t) {
	// printf("tanri,  %d, %d, %lf, %d\n", y, m, n, t);
	int risi=0;
	for (int i=0; i<y; i++) {
		risi += m*n;
		m -= t;
	}
	// printf("\n Ans %d \n", m+risi);
	return m+risi;
}

int main() {
	int m, M, Y, n, type, T;
	double Nenri;
	scanf("%d", &m);
	for (int i=0; i<m; i++) {
		int max=0;
		scanf("%d%d%d", &M, &Y, &n);
		for (int j=0; j<n;j++) {
			int L;
			scanf("%d%lf%d", &type, &Nenri, &T);
			if(type) {
				L = Hukuri(Y, M, Nenri, T);
			} else {
				L = Tanri(Y, M, Nenri, T);
			}
			if (max < L) {max = L;}
		}
		printf("%d\n", max);
	}
}
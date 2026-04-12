#include <bits/stdc++.h>
using namespace std;

#define MODULO 1000000007

int main() {
	int n;
	cin >> n;
	long int* v = (long int*) malloc (n * sizeof(long int));
	long int* sumP = (long int*) malloc ((n - 1) * sizeof(long int));

	for (int i = 0; i < n; i++) {
		long int aux;
		cin >> aux;
		v[i] = aux;
	}

	sumP[n - 2] = v[n - 1];
	for (int i = n - 3; i >= 0; i--) {
		long int aux = ((sumP[i + 1] % MODULO) + (v[i + 1] % MODULO)) % MODULO;
		sumP[i] = aux;
	}


	long int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		long int prod = ((v[i] % (MODULO)) * (sumP[i] % (MODULO))) % MODULO;
		sum = ((prod % MODULO) + (sum % MODULO)) % MODULO;
	}

	cout << sum;
}
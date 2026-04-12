#include <bits/stdc++.h>
using namespace std;


int main()
{
	int l, N, X = 1, i = 0, a[20];
	cin >> N;
	while (cin >> l) {
		a[i] = l;
		i++;
		if (i >= N) {
			break;
		}
	}
	

	for (i = 1; i < N; i++) {
		int max = a[0];
		for (int j = 1; j < i+1; j++) {
			if (a[j] >= max) {
				max = a[j];
			}
		}
		if (a[i] >= max) {
			X = X + 1;
		}	
	}

	cout << X << endl;
}
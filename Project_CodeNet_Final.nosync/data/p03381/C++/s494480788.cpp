#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define INF (1<<31-1)
#define ll long long

int N;
int x[200001], y[200001];

int main(){

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> x[i];
		y[i] = x[i];
	}

	sort(x, x + N);

	int m1, m2;
	m1 = x[N / 2 - 1];
	m2 = x[N / 2];

	for (int i = 0; i < N; i++){
		if (y[i] <= m1) cout << m2 << endl;
		else cout << m1 << endl;
	}



	return 0;
}

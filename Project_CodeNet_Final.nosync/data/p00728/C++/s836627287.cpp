
#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include<map>
#include<type_traits>

long long int D[10000];
long long int E[400000];

using namespace std;
int main() {
	long long int N;
	long long int Y = -1;
	cin >> N;
	while (N) {
		Y++;
		for (long long int i = 0; i < N; i++) {
			cin >> D[i];
		}

		sort(D, D + N);
		long long int W = 0;
		for (long long int i = 1; i < N-1; i++) {
			W += D[i];
		}
		E[Y] = W / (N-2);
		cin >> N;
		
	}

	for (long long int i = 0; i <=Y ;i++) {
		cout << E[i] << endl;
	}
	return 0;
}



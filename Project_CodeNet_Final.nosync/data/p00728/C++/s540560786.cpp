#include <iostream>
using namespace std;

int main (){
	int n, i, max, min;
	int A[101];
	int sum;
	while (cin >> n && n > 0){
		sum = 0;
		for (i = 0; i < n; i++){
			cin >> A[i];
		}
		max = min = A[0];
		for (i = 0; i < n; i++){
			if (max < A[i]){
				max = A[i];
			}
			if (min > A[i]){
				min = A[i];
			}
			sum += A[i];
		}
		sum -= max;
		sum -= min;
		cout << sum / (n - 2) << endl;
	}

	return 0;
}

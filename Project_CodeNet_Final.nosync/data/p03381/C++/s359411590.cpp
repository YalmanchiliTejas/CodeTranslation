#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	int N;
  	cin >> N;
  	int X[N];
  	for (int i = 0; i < N; i++) cin >> X[i];
  
  	int A[N];
  	for (int i = 0; i < N; i++) A[i] = X[i];
  
  	sort(A, A + N);
  	int median[2];
  	median[0] = A[N / 2 - 1];
  	median[1] = A[N / 2];
  
  	int res[N];
  
  	for (int i = 0; i < N; i++){
      	if (median[0] >= X[i]) res[i] = median[1];
      	else res[i] = median[0];
    }
  
  	for (int i = 0; i < N; i++) cout << res[i] << endl;
}
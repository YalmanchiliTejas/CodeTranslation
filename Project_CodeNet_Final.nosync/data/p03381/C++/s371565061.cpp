#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int A[300000], B[300000];

int main() {
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
		B[i] = A[i];
	}
	
	sort(A, A + N);
	
	for(int i = 0; i < N; i++){
		if(B[i] < A[N / 2]){
			cout << A[N / 2] << endl;
		}else{
			cout << A[N / 2 - 1] << endl;
		}
	}
	
	return 0;
}

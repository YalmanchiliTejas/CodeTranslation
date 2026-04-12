#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	long long int A[100010] = {}, B[100010] = {}; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
	}
	sort(A, A+N); 
	for(int i = 0; i < N-1; i++){
		B[i] = A[i+1] - A[i]; 
	}
	long long int C[100010] = {}; 
	for(int i = 0; i < N; i++){
		C[i] = min(2 * (i + 1), 2 * (N - 1 - i)); 
	}
	long long int ans = 0; 
	for(int i = 0; i < N - 1; i++){
		ans += B[i] * C[i]; 
	}
	if(N % 2 == 0){
		cout << ans - B[N/2 - 1] << endl; 
	}
	else if(N % 2 == 1){
		cout << ans - min(B[N/2 - 1], B[N/2]) << endl; 
	}
}
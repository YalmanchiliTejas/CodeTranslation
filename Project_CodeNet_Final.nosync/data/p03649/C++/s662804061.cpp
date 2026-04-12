#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; long long A[55] = {}; 
	cin >> N; long long S = 0; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; S += A[i]; 
	}
	while(1){
		bool finished = true; 		
		for(int i = 0; i < N; i++){
			long long p = A[i] / N; 
			A[i] = A[i] % N; 			
			for(int j = 0; j < N; j++){
				if(j == i) continue; 
				A[j] += p; 
			}
		}
		for(int i = 0; i < N; i++){
			if(A[i] >= (long long) N) finished = false; 
		}
		if(finished) break; 
	}
	long long T = 0; 
	for(int i = 0; i < N; i++){
		T += A[i]; 
	}
	cout << S - T << endl; 
}
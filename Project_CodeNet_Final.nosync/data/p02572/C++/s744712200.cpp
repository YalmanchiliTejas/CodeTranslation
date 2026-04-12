#include <bits/stdc++.h>
using namespace std;
int main(){
	long long mod = 1000000007; 
	long long sum = 0; 
	long long sq = 0; 
	long long A[200010] = {};
	int N; cin >> N;  
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
		sum += A[i]; 
		sum %= mod; 
		sq += A[i] * A[i] % mod; 
		sq %= mod; 
	}
	long long ans = mod + sum * sum % mod - sq; 	
	cout << ans * 500000004 % mod << "\n"; 
}
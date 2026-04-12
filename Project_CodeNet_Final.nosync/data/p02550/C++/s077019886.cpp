#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long N, X, M; cin >> N >> X >> M; 
	long long loopin = -1; 
	long long period = 0; 
	long long tmp = X; 
	long long A[114514] = {}; 
	long long S[114514] = {}; 
	A[1] = X; 
	for(int i = 2; i <= 100050; i++){
		tmp *= tmp; tmp %= M; 
		A[i] = tmp; 
	}
	for(int i = 1; i <= 100050; i++){
		S[i] = A[i] + S[i-1]; 
	}
	int exist[100010] = {}; 
	for(int i = 1; i <= 100050; i++){
		if(exist[A[i]]){
			loopin = exist[A[i]]; 
			period = i - exist[A[i]]; 
			break; 
		}
		exist[A[i]] = i; 
	}
	if(N <= M){
		cout << S[N] << "\n"; return 0; 
	}else{
		long long cycle = S[loopin + period - 1] - S[loopin - 1]; 
		long long rem = N - loopin + 1; 
		long long times = rem / period; 
		long long nokori = rem % period; 
		cout << cycle * times + S[loopin + nokori - 1] << "\n"; 
		return 0; 
	}
}
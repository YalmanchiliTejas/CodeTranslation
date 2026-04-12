#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long int Inv(long long int a, long long int m) {
	long long int c[50];
  	long long int e[50];  
  	c[0] = (m-2) % 2, e[0] = (m-2) / 2; 
  	for (int i = 0; i < 49; ++i){
     		c[i+1] = e[i] % 2; e[i+1] = e[i] / 2;  
  	}
	long long int d[50]; 
  	d[0] = a; 
  	for (int j = 0; j < 49; ++j){
     		d[j+1] = (d[j] * d[j]) % m; 
  	}
  	long long int Q = 1; 
	for(int k = 0; k < 49; ++k){
  		if(c[k] == 1) Q = (Q * d[k]) % m; 
	}
	return Q;
}
int main(){
	long long int N, M, K; cin >> N >> M >> K; 
	long long int P = 1e9 + 7; 
	long long int a = ((N * N * N - N) / 6) % P; 
	long long int b = ((M * M * M - M) / 6) % P; 
	long long int c = (((M * M) % P) * a) % P; 
	long long int d = (((N * N) % P) * b) % P; 
	long long int x = (c + d) % P; 
	long long int Fac[200100] = {}; Fac[0] = 1; 
	for(int i = 1; i < 200030; i++){
		Fac[i] = (Fac[i-1] * i) % P; 
	}
	long long int e = Fac[M*N-2]; 
	long long int f = Inv(Fac[K-2], P); 
	long long int g = Inv(Fac[M*N-K], P); 
	long long int h = (((e * f) % P) * g) % P; 
	cout << (x * h) % P << endl; 
}
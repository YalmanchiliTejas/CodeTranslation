#include<bits/stdc++.h>
using namespace std;
#define N 51

long long L[N], P[N];

long long f(long long n){
	if(L[n] == -1){
		if(n == 0){
			P[n] = L[n] = 1;
		} else {
			L[n] = 1 + f(n-1) + 1 + f(n-1) + 1; 
			P[n] = P[n-1]*2 + 1;
		}
	}
	return L[n];
}

long long g(int n, long long x){
	long long total = 0;
	if(n >= 0 && x > 0){
		if(L[n] <= x)
			return P[n];
		else if(x > 0){
			x--;
			if(x >= L[n-1]){
				x -= L[n-1];
			
				total += P[n-1];
				if(x >= 1) {
					x--;
					total++;
					if(x >= L[n-1]){
						x-= L[n-1];
						total += P[n-1];
					} else {
						total += g(n-1, x);
					}
				}
			} else {
				total += g(n-1, x);
			}
			x--;
		}
	}
	return total;
}

int main(){
	for(int i = 0 ; i < N ; i++){
		P[i] = L[i] = -1;
	}

	long long n, x;
	cin >> n >> x;
	f(n);
	// cout << f(n) << endl;
	// cout << P[n] << endl;
	cout << g(n, x) << endl;
	return 0;
}


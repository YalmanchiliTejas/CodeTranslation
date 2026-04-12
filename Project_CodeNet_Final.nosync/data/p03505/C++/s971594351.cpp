#include <bits/stdc++.h>
using namespace std;
int main(){
	long long K, A, B; cin >> K >> A >> B; 
	if(A >= K){
		cout << 1 << "\n"; return 0;
	}else if(A <= B){
		cout << -1 << "\n"; return 0; 
	}else{
		cout << 1 + (K - B - 1) / (A - B) * 2 << "\n"; return 0; 
	}
}
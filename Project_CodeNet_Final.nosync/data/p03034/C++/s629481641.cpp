#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	int N; long long int S[100010] = {}; 
	cin >> N; 
	for(int i = 0; i < N; i++){
		cin >> S[i]; 
	}
	long long int ans = 0; // m=A-Bとするとmは1以上N-1以下
	for(int m = 1; m < N; m++){
		long long int mx = 0; 
		long long int tmp = 0; // S[0] + S[N-1] から始めて次は S[m] + S[N-1-m] を足す感じ
		for(int j = 1; N - 1 - j * m > m; j++){ // B > 0 に注意！
			if((N - 1) % m == 0 && N - 1 - j * m <= j * m) break; 
			tmp += S[j * m] + S[N - 1 - j * m]; 
			mx = max(mx, tmp); 
		}
		ans = max(ans, mx); 
	}
	cout << ans << endl; 
}
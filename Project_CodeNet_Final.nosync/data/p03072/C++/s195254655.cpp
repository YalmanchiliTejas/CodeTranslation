#include <bits/stdc++.h>
using namespace std; 
int main(){
	int N; 
	cin >> N; 
	int H[25] = {}; 
	cin >> H[0]; 
	int mx = H[0]; 
	int ans = 1; 
	for(int i = 1; i < N; i++){
		cin >> H[i]; 
		if(H[i] >= mx){
			ans ++; 
			mx = H[i]; 
		}
	}
	cout << ans << endl; 
}
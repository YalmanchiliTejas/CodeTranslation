#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, max=0, sum=0;
	int h[100];
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> h[i];
		if(h[i]>=max) {
			sum++; 
			max = h[i];
		}
	}
	
	cout << sum << endl;
	
	return 0;
}

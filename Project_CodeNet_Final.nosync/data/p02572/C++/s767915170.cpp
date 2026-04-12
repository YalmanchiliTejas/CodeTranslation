#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long  arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	long long sumarr[n];
	sumarr[0] = arr[0];
	for(int i=1;i<n;i++){
		sumarr[i] = arr[i] + sumarr[i-1];
	}
	long long sum = 0;
	for(int i=0;i<n;i++){
		sum = (sum%(long long)((1e9)+7) + ((arr[i]%(long long)((1e9)+7))*((sumarr[n-1] - sumarr[i])%(long long)((1e9)+7)))%(long long)((1e9)+7))%(long long)((1e9)+7);
	}
	cout << sum << endl;
}

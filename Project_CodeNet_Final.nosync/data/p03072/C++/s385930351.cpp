#include <bits/stdc++.h>
using namespace std;
int main (){
	
	int n;
	int cont=0;
	cin >> n;
	int a[n];
	bool mayor = true;
	for (int i=0; i<n; i++){
		cin >> a[i];
		for(int j=0;j<=i && mayor; j++){
			if (a[j] > a[i]){
				mayor = false; 
			}
		}
		if (mayor) cont++; 
		mayor = true;
	}
	cout << cont;
	return 0;
}
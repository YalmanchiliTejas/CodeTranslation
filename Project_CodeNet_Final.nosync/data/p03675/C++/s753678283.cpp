#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[300000];
int b[300000];

int main(){
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; n - 1 - i * 2 >= 0; i++){
		b[i] = a[n - 1 - i * 2];
	}
	for(int i = (n + 1) / 2; i < n; i++){
		b[i] = a[(i - (n + 1) / 2) * 2 + n % 2];
	}
	
	for(int i = 0; i < n; i++){
		cout << b[i];
		if(i != n - 1){
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}

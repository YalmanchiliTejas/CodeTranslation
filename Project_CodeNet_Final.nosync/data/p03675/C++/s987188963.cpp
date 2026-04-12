#include <iostream>
using namespace std;

int main() {
	int n;
	cin >>n;
	int a[n+1]={};
	for (int i=1;i<=n;i++){
		cin >> a[i];	
	}
	for (int i=n;i>=2-n%2;i=i-2){
		cout << a[i] << ' ';
	}
	for (int i=n%2+1;i<=n-1;i=i+2){
		cout << a[i] << ' ';
	}
	return 0;
}
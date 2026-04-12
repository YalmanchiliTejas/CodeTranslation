#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[25];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
    int max = -1000000;
	for (int j = 0; j < n; j++) {
		if(a[j]>=max){
		    max = a[j];
		    sum++;
		}
		
	}
	cout << sum << endl;
	return 0;
}
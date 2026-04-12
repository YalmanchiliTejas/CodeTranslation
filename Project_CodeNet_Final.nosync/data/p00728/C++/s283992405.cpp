#include <iostream>
using namespace std;

int main() {
	int n, a[100];
	while(1){
		cin >> n;
		if(n==0) break;
		int min, max, sum, avg;
		for(int i=0; i<n; i++)
			cin >> a[i];
			min = max = sum = a[0];
		for(int j=1; j<n; j++){
			sum += a[j];
			if(min>a[j]) min = a[j];
			if(max<a[j]) max = a[j];
		}
		avg = (sum-max-min)/(n-2);
		cout << avg << endl;
	}
	return 0;
}

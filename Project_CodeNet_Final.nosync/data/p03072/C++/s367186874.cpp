#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	std::cin >> n;

	int l, i = 0, a[30];
	while (std::cin >> l) {
		a[i] = l;
		i++;
		if (i >= n) {
			break;
		}
	}

	int t;
	int max = 0;
	int total= 0;
	for (t = 0; t < n; t++) {
		if(a[t]>=max){
			total += 1;
			max = a[t];
		}
	}

	cout << total;

 
	

	return 0;
}
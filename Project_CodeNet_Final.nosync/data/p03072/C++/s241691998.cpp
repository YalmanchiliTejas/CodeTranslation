#include<iostream>
using namespace std;


int main(){
	int a[20];
	int i,n,max=0,z=0;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a[i];

	
	}


	for (i = 0; i < n; i++) {
		if (a[i] >= max) {
			z++;
			max = a[i];
		
		}
	
	
	
	}


	cout << z;



	return 0;
	}
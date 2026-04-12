#include<iostream>
using namespace std;

int main(){
	int n;
	int h[100];
	int i, j;
	int max;
	int count = 0;

	cin >> n;
	for (i = 0; i < n; i++){
		cin >> h[i];
	}

	max = h[0];
	for (i = 0; i < n; i++){
		if (max <= h[i]){
			count++;
			max = h[i];
		}
	}

	cout << count << endl;

	return 0;
}
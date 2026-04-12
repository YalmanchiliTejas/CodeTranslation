#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
	int n;

	cin >> n;

	vector<int> x(n + 1, 0), y(n + 1, 0);

	for (int i = 0; i < n; i++){
		cin >> x[i + 1];
		y[i + 1] = x[i + 1];
	}


	sort(y.begin(), y.end());
	reverse(y.begin(), y.end());


	int mid = y[n/2-1];;


	for (int i = 1; i < n + 1; i++){
		if (x[i] < mid){
			cout << mid << endl;
		}
		else 
			cout << y[n/2] << endl;
	}
}
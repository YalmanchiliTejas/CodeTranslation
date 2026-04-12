#include<iostream>

using	namespace std;

int main() {
	
	int temp,N,max,count=1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (i == 0) {
			max = temp;
		}
		else if (max <= temp) {
			count++;
			max = temp;
		}
	}
	cout << count << endl;
}
#include <bits/stdc++.h>

using namespace std;



int main() {

	int n;
	cin >> n ;

	int h[101];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int counter =1;
	for (int i = 1; i < n; i++) {
		bool yn = true;
		for (int j = 0; j <= i - 1; j++) {
			if (h[i] < h[j]) {
				yn = false;
				break;
			}

		}
		if(yn==true){counter++;}

	}
	cout << counter << endl;

}
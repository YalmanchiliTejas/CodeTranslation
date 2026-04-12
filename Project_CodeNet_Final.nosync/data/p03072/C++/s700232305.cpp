/* B */

#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int* h = new int[n];

	for(int i = 0; i < n; i++){
		cin >> h[i];
	}

	int m = 0, cnt = 0;

	for(int i = 0; i < n; i++){
		if(h[i] >= m){
			cnt++;
			m = h[i];
		}
	}	

	cout << cnt << endl;
}
#include <iostream>
using namespace std;

int main(){
	int n, h[20], look, result = 1;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> h[i];
		if(i >= 1){
			look = 0;
			for(int j = 0; j < i; j++) if(h[i] < h[j]) look = 1;
			if(look == 0) result++;
		}
	}
	cout << result << endl;
	return 0;
}
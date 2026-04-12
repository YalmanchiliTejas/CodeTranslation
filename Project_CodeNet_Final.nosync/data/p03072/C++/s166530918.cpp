#include <iostream>
using namespace std;

int main() {

	int N, H[100] = {0};
	int cnt = 0, high = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}
	
	cnt++;
	high = H[0];

	for(int i = 1; i < N; i++){
		if(high <= H[i]){
			high = H[i];
			cnt++;
		}
	}
	
	cout << cnt << "\n";

	return 0;
}
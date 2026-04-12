#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	int H[N];
	for(int k = 0; k < N; k++){
		cin >> H[k];
	}

	int ans = 0;
	for(int i = 0; i < N; i++){
		int count = 0;
		for(int j = 0; j < i; j++){
			if(H[i] >= H[j]){
				count++;
			}
		}
		if(count == i){
			ans++;
		}
	}
	cout << ans << endl;

}
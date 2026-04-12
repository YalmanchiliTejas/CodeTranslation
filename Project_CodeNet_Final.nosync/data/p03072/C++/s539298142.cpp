#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int H[N];
	int count = 1;
	int viewable = 0;
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}
	for(int i = 1; i < N; i++){
		viewable = 1;
		for(int j = 0; j < i; j++){
			if(H[j] > H[i]){
				viewable = 0;
				break;
			}
		}
		if(viewable == 1){
			count++;
		}
	}
	cout << count;
	return 0;
}
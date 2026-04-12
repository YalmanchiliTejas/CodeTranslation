#include <iostream>
#include <string>
using namespace std;

int N;
int H[22];

int main(){
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> H[i];
	int count = 1;
	int norm = -1;
	for (int i = 1; i < N; ++i){
		for (int j = 0; j < i; ++j){
			norm = max(norm, H[j]);
		}
		if(H[i] >= norm) count++;
		norm = -1;
	}

	cout << count << endl;
}
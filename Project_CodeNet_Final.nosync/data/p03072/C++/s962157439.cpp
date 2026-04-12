#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, max_h = 0, count = 0;
	vector<int> H;

	cin >> N;
	for(int i = 0; i < N; ++i){
		int Hi;
		cin >> Hi;
		H.push_back(Hi);
	}

	max_h = H[0];
	for(int i = 0; i < N; ++i){
		if(max_h <= H[i]){
			count++;
		}

		if(max_h < H[i]) max_h = H[i];
	}

	cout << count << endl;

	return 0;
}

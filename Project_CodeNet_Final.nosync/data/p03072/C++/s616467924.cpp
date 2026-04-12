#include"bits/stdc++.h"
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	int count = 0, hight = 0;
	for (int i = 0;i < N;++i) {
		cin >> H[i];
		if (H[i] >= hight) {
			count++;
			hight = H[i];
		}
	}
	cout << count << endl;
	return 0;
}
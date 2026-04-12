#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	vector<int> Hmax(N);
	int maxim = 0;
	for (int i = 0; i < N; i++) {
		
		if (H[i] > maxim) {
			maxim = H[i];
		}
		Hmax[i] = maxim;
	}
	


	int count = 0;
	for (int i = 0; i < N; i++) {
		if (H[i] == Hmax[i]) count++;
	}
	cout << count << endl;
}
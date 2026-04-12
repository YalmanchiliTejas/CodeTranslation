#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>H(N);
	for (int i = 0;i < N;i++) {
		cin >> H[i];
	}
	int count = 0;
	for (int i = 0;i < N;i++) {
		if (H[0] == H[i]) {
			count++;
		}
		else if (H[0] < H[i]) {
			H[0] = H[i];
			count++;
		}
	}
	cout << count << endl;
}
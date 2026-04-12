#include<iostream>
#include<vector>
using namespace std;

int main() {

	//入力
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	int ans = 0; //答えとなる山の数
	int maxheight = 0; //今までで最も高い山の高さ

	//今見ている山
	for (int i = 0; i < N; i++) {
		if (maxheight <= H[i]) {
			ans++;
			maxheight = H[i];
		}
	}

	cout << ans << endl;
}
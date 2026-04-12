#include<iostream>

using namespace std;

int main() {
	int N;
	int x = 0;//支払った額
	int y = 0;//もらった額

	//入力
	cin >> N;

	//支払った額を計算
	for (int i = 0; i < N; i++) {
		x = x + 800;
	}

	//もらった額を計算
	for (int i = 0; i < N; i++) {
		if ((i + 1) % 15 == 0) {
			y = y + 200;
		}
	}

	//出力
	cout << x - y << endl;
}

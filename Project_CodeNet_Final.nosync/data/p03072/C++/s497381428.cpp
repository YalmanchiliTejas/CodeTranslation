#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//入力
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}

	//処理
	int ans = 0;
	//i 今見ている山
	for (int i = 0; i < N; i++)
	{
		//自分より高い山がなかったかどうかのフラグ
		bool flag = true;

		//j これから調べる山 iより西側なので、i未満について調べる
		for (int j = 0; j < i; j++)
		{
			if (H[j] > H[i]) flag = false;
		}

		if (flag) ans++;
	}

	//出力
	cout << ans << endl;
}


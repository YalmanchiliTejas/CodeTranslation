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
	//これまで最も高かった山
	int MaxHeight = -1;

	//i 今見ている山
	for (int i = 0; i < N; i++)
	{
		//今までで一番高い山を見つけたら、答えに1を足して、高さを更新する
		if (MaxHeight <= H[i]) {
			ans++;
			MaxHeight = H[i];
		}
	}

	//出力
	cout << ans << endl;
}


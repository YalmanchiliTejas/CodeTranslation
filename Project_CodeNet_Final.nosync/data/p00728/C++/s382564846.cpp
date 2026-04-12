#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n,score[101];
	while (cin >> n, n){

		//初期化
		for (int i = 0; i < 101; i++)
			score[i] = 0;
		int sum = 0;
		int maxs = 0;
		int mins = 1001;


		//入力
		for (int i = 0; i < n; i++){
			cin >> score[i];
			sum += score[i];
		}

		//最大，最小
		for (int i = 0; i < n; i++){
			maxs = max(maxs, score[i]);
			mins = min(mins, score[i]);
		}

		cout << (sum - maxs - mins) / (n - 2) << endl;

	}

	return 0;
}
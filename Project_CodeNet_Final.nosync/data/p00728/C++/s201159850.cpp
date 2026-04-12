#include<iostream>

#define     MIN_POINT     0
#define     MAX_POINT     1000

using namespace std;

int main(){
	int n;

	// ループ
	cin >> n;
	while(n >= 3){
		int min = (int)(MAX_POINT), max = (int)(MIN_POINT);
		int sum = (min + max) * (-1);
		int i, buf;

		// 点数の入力・合計処理
		for(i=0;i<n;i++){
			// 入力
			cin >> buf;
			// 入力値のチェック
			if((buf < ((int)(MIN_POINT))) || (buf > ((int)(MAX_POINT)))){
				cerr << "入力された値が範囲外です" << endl;
				i--;
				continue;
			}
			// 合計値に加算
			sum += buf;
			// 最大値のチェック
			if(buf > max){
				sum += max;
				max = buf;
				sum -= max;
			}
			// 最小値のチェック
			if(buf < min){
				sum += min;
				min = buf;
				sum -= min;
			}
		}

		// 合計の表示
		cout << (sum / (n - 2)) << endl;

		// 入力
		cin >> n;
	}

	return 0;
}
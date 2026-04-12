// 2020/08/17 Tazoe

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int d[300000];
	for(int i=0; i<N; i++){
		cin >> d[i];
	}

	// 往路

	int D = 0;					// 現時点の最大距離

	for(int i=0; i<N-1; i++){	// 左端から右端へ
		D = max(D, d[i]);			// 最大距離の更新

		if(D<10){					// 次に跳べないならば
			cout << "no" << endl;
			return 0;
		}

		D -= 10;					// 次に跳んだ
	}

	// 復路

	D = 0;

	for(int i=N-1; i>0; i--){	// 右端から左端へ
		D = max(D, d[i]);

		if(D<10){
			cout << "no" << endl;
			return 0;
		}

		D -= 10;
	}

	cout << "yes" << endl;
	return 0;
}


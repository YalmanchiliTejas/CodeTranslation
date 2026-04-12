#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main() {
	//入力
	int N;
	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	
	//処理
	int ans = 0;
	for(int i = 0; i < N; i++) {
		bool flag = true;

		for (int j = 0; j < i; j++) {
			if (vec[j] > vec[i]) flag = false;
		}
		if (flag) ans++;
	}
	cout << ans << endl;
}

#include <iostream>
#include <stdio.h>
#include <math.h> 
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

int main()
{
	vector<int> mnt;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		cin >> tmp;
		mnt.push_back(tmp);
	}

	int ans = 1;

	vector<int> tmp;
	tmp.push_back(mnt[0]);

	for (int i = 1; i < n; ++i) {
		//最初を除く今見ている値が、それまでの最大値を超えているときにカウンタを増やす
		tmp.push_back(mnt[i]);
		sort(tmp.begin(), tmp.end(), std::greater<int>());
		if (mnt[i] >= tmp[0]) {
			ans++;
		}


	}

	cout << ans << endl;


}
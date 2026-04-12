#include <bits/stdc++.h>
using namespace std;
int main()
{
	// 整数の入力
	
	int n, max, num;
	cin >> n;
	vector<int> h(20);
	for (int i = 0; i < n; i++)
	{
		cin >> h.at(i);
	}
	max = 0;
  num=0;
	for (int i = 0; i < n; i++)
	{
		if (h.at(i) >= max) {
			num++;
			max = h.at(i);
		}

	}

	
	// 出力
	cout << num<< endl;
	//return 0;
}
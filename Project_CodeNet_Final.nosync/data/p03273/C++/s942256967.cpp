#include "bits/stdc++.h"
using namespace std;
#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(i = 0; i < n; i++)
const long long INF = 1LL << 60;
typedef long long ll;

int main()
{
	int H, W;
	cin >> H >> W;
	char table[120][120];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> table[i][j];
		}
	}

	vector<int> H_zip;
	vector<int> W_zip;

	for (int i = 0; i < H; i++)
	{
		int flag = 0;

		for (int j = 0; j < W; j++)
		{
			if (table[i][j] == '#') {
				flag = 1;
				//cout << "hi" << endl;
				break;
			}
		}
		if (flag)
		{
			H_zip.push_back(i);
		}
	}

	for (int i = 0; i < W; i++)
	{
		int flag = 0;
		for (int j = 0; j < H; j++)
		{
			if (table[j][i] == '#') {
				flag = 1;
				//cout << "hi" << endl;
				break;
			}
		}
		if (flag)
		{
			W_zip.push_back(i);
		}
	}

	
	for (int i = 0; i < H_zip.size(); i++)
	{
		for (int j = 0; j < W_zip.size(); j++)
		{
			int x = H_zip[i];
			int y = W_zip[j];
			cout << table[x][y];
		}
		cout << endl;
	}
	\
}

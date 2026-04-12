#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 入力
	int H, W;
	cin >> H >> W;
	vector<vector<char>> squares(H, vector<char>(W));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			char a;
			cin >> a;
			squares[i][j] = a;
		}
	}
	
	// 行
	vector<bool> isAllRowWhite(H, true);
	// 列
	vector<bool> isAllColWhite(W, true);
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			// 黒の場合
			if (squares[i][j] == '#') {
				isAllRowWhite[i] = false;
				isAllColWhite[j] = false;
			}
		}
	}
	
	// 出力
	for (int i = 0; i < H; i++)
	{
		// 行が黒の場合
		if (!isAllRowWhite[i])
		{
			for (int j = 0; j < W; j++)
			{
				// 列が黒の場合
				if (!isAllColWhite[j])
				{
					cout << squares[i][j];
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}


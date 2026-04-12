#include <iostream>
#include <string>
using namespace std;

bool IsW(string s,int W) {
	bool flg = true;
	for (int i = 0; i < W; i++)
	{
		if (s[i] == '#')
			flg = false;
	}
	return flg;
}

bool IsH(string s[], int H, int k) {
	bool flg = true;
	for (int i = 0; i < H; i++)
	{
		if (s[i][k] == '#')
			flg = false;
	}
	return flg;
}

int main() {
	string S[110];
	int H, W;

	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		cin >> S[i];
	}

	//cout << endl;

	for (int i = 0; i < H; i++)
	{
		if (IsW(S[i], W)) {
			string tmp = S[i];
			int j = i;
			for (; j < H; j++)
			{
				S[j] = S[j + 1];
			}
			S[j] = tmp;
			H--;
			i--;
		}
	}
	
	for (int i = 0; i < W; i++)
	{
		//cout << IsH(S, H, i) << endl;
		if (IsH(S, H,i)) {
			for (int j = 0; j < H; j++)
			{
				int k = i;
				char tmp = S[j][k];
				for (; k < W; k++)
				{
					S[j][k] = S[j][k+1];
				}
				S[j][k] = tmp;
			}
			i--;
			W--;
		}
	}
	
	//結果
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << S[i][j];
		}
		cout << endl;
	}

	return 0;
}
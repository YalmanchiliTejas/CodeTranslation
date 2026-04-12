//
//  main.cpp
//  ABC107B
//
//  Created by KJC of Kindai University on 2019/08/04.
//  Copyright © 2019 KJC of Kindai University. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
	// insert code here...
	int H, W;
	cin >> H >> W;
	//cout << H << endl;
	//cout << W << endl;

	vector<string> s(H);// スペース区切りではないので、string型として行ごとに読み込む
	vector<vector<int>>Table(H, vector<int>(W));

	vector<int>memo_h(H, 0);
	vector<int>memo_w(W, 0);
	for (int i = 0; i < H; i++)
	{
		cin >> s.at(i);
		for (int j = 0; j < W; j++)
		{
			if (s.at(i).at(j) == '#') //Char型のときは' 'で囲む
			{
				Table.at(i).at(j) = 1;
				memo_h.at(i)++;
				memo_w.at(j)++;
			}
			else
			{
				Table.at(i).at(j) = 0;
			}
		}
	}
	//
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (memo_h.at(i) != 0 && memo_w.at(j) != 0)
			{
				cout << s.at(i).at(j);
			}
			if (memo_h.at(i) != 0&&j==W-1)
			{
				cout << endl;
			}
		}
	}
	return 0;
}

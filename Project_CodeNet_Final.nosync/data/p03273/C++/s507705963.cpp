#include <bits/stdc++.h>
using namespace std;
int main () {
	int H,W;
	cin >> H >> W;
	int grid[H][W];
	std::vector<int> skipX;
	std::vector<int> skipY;
	for (int y = 0; y < H; ++y)
	{
		for (int x = 0; x < W; ++x)
		{
			char tmp;
			cin >> tmp;
			if(tmp == '#'){
				grid[y][x] = 1;
			}else{
				grid[y][x] = 0;
			}
		}
	}
	for (int y = 0; y < H; ++y)
	{
		bool tmp = false;
		for (int x = 0; x < W; ++x)
		{
			if(grid[y][x] == 1)tmp = true;
		}
		if(!tmp)skipY.push_back(y);
	}
	for (int x = 0; x < W; ++x)
	{
		bool tmp = false;
		for (int y = 0; y < H; ++y)
		{
			if(grid[y][x] == 1)tmp = true;
		}
		if(!tmp)skipX.push_back(x);
	}
	for (int i = 0; i < (int)skipX.size(); ++i)
	{
		//cout << skipX[i] << endl;
	}
	for (int i = 0; i < (int)skipY.size(); ++i)
	{
		//cout << skipX[i] << endl;
	}
	for (int y = 0; y < H; ++y)
	{
		auto it = find(skipY.begin(), skipY.end(),y);
		if(it == skipY.end()){
			for (int x = 0; x < W; ++x)
			{
				it = find(skipX.begin(), skipX.end(),x);
				if(it == skipX.end()){
					if(grid[y][x] == 1){
						cout<<'#';
					}else{
						cout<<'.';
					}
				}else{
					//cout << "X" << x << "is deleted" << endl;
				}
			}
			cout << endl;
		}else{
			//cout << "Y" << y << "is deleted" << endl;
		}

	}

}
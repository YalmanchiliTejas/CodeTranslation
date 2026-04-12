#define _USE_MATH_DEFINES
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   

using namespace std;

int main() {
	int h, w;
	string board[110];

	cin >> h >> w;

	vector<bool> row(h, false);
	vector<bool> col(w, false);

	for (int i = 0; i < h; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	
	for (int i = 0; i < h; i++)
	{
		if (row[i]) {
			for (int j = 0; j < w; j++)
			{
				if (col[j]) {
					cout << board[i][j];
				}
			}
			cout << endl;
		}
		
	}
}
#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<cstdlib>
#include<list>
#include<set>
#include<numeric>

#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

char board[10][10];
int H, W;

int main()
{
	cin >> H >> W;
	
	for (int i = 0; i < H; i++)
		cin >> board[i];

	int num = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '#')num++;
		}
	}
	if (H + W - 1 == num)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <complex>

using namespace std;

// #define mod 1000000007

int c[4][4];

int paint(int nowstate, int i, int j, int k, int l, int nowc)
{
	int result = nowstate;
	for(int s = i; s <= k; s++){
		for(int t = j; t <= l; t++){
			if(c[s][t] == nowc) result |= (1 << (4 * s + t));
			else result &= ~(1 << (4 * s + t));
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int canpaint[4][4][4][4] = {};
	// canpaint[i][j][k][l] : 右下が(i, j), 左上が(k, l)となるような範囲を塗れるスタンプがあるか否か
	for(int p = 0; p < n; p++){
		int h, w;
		cin >> h >> w;
		for(int i = -h + 1; i < 4; i++){
			for(int j = -w + 1; j < 4; j++){
				canpaint[max(i, 0)][max(j, 0)][min(i + h - 1, 3)][min(j + w - 1, 3)] = true;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			char tmp;
			cin >> tmp;
			if(tmp == 'R') c[i][j] = 0;
			else if(tmp == 'G') c[i][j] = 1;
			else c[i][j] = 2;
		}
	}
	vector<int> result((1 << 16), -1);
	queue<int> qu;
	result[0] = 0;
	qu.push(0);
	while(!qu.empty()){
		int p = qu.front();
		// cout << p << endl;
		qu.pop();
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				for(int k = i; k < 4; k++){
					for(int l = j; l < 4; l++){
						if(!canpaint[i][j][k][l]) continue;
						for(int nowc = 0; nowc < 3; nowc++){
							int next = paint(p, i, j, k, l, nowc);
							if(result[next] < 0){
								result[next] = result[p] + 1;
								qu.push(next);
							}
						}
					}
				}
			}
		}
	}
	cout << result[(1 << 16) - 1] << endl;
	return 0;
}

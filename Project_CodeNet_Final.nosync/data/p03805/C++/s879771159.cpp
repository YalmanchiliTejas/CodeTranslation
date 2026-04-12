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

using namespace std;

#define mod 1000000007

int main()
{
	int n, m;
	cin >> n >> m;
	int graph[8][8] = {};
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = graph[b][a] = 1;
	}
	int result[1 << 8][8][8] = {};
	// result[i][j][k]: iを二進数表現で通る頂点、jスタートでkが終わりになるような通り方
	for(int i = 0; i < n; i++){
		result[1 << i][i][i] = 1;
	}
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) == 0) continue;
			for(int k = 0; k < n; k++){
				if((i & (1 << k)) == 0) continue;
				// jスタートでkが終わりとする
				for(int l = 0; l < n; l++){
					if((i & (1 << l)) != 0 || graph[k][l] == 0) continue;
					// l: 次に通る頂点
					result[i | (1 << l)][j][l] += result[i][j][k];
				}
				// cout << i << " " << j << " " << k << " " << result[i][j][k] << endl;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += result[(1 << n) - 1][0][i];
	}
	cout << ans << endl;
	return 0;
}
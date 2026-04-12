#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <list>
#include <cstring>
#include <stack>

using namespace std;

#define mod 1000000007


vector<int> result((1 << 16), -1);

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int d[16];
	vector<int> isdark(101, -1);
	for(int i = 0; i < m; i++){
		cin >> d[i];
		d[i]--;
		isdark[d[i]] = i;
	}
	int v[101][101];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	result[(1 << m) - 1] = 0;
	queue<int> qu;
	qu.push((1 << m) - 1);
	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		for(int j = 0; j < k; j++){
			// 状態nowから、j番目の道を選んだとする
			int next = 0;
			for(int l = 0; l < m; l++){
				// l番目のくらい部屋にいる人が次どこに行くかを考える
				if((now & (1 << l)) == 0) continue;
				int nextroom = v[d[l]][j];
				if(isdark[nextroom] >= 0) next |= (1 << isdark[nextroom]);
			}
			if(result[next] == -1){
				result[next] = result[now] + 1;
				qu.push(next);
			}
		}
	}
	cout << result[0] << endl;
	return 0;
}

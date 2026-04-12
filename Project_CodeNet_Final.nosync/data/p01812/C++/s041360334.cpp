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

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> darkroom;
	int d[16];
	for(int i = 0; i < m; i++){
		cin >> d[i];
		d[i]--;
		darkroom[d[i]] = i;
	}
	vector<vector<int> > path(101);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int v;
			cin >> v;
			v--;
			path[i].push_back(v);
		}
	}
	vector<int> result((1 << m), mod);
	result[(1 << m) - 1] = 0;
	// 1????????£???????????¨??????????????????????????¨??????????????????????????????????????¨?±?
	queue<int> qu;
	qu.push((1 << m) - 1);
	while(!qu.empty()){
		int i = qu.front();
		qu.pop();
		for(int j = 0; j < k; j++){
			// ?¬????j????????????????????¶??¨??????
			int next = 0;
			for(int l = 0; l < m; l++){
				int roomnum = d[l];
				if((i & (1 << l)) != 0 && darkroom.find(path[roomnum][j]) != darkroom.end()){
					next = (next | (1 << darkroom[path[roomnum][j]]));
				}
			}
			// cout << i << " " << result[i] << " " << j << " " << next << endl;
			if(result[next] > result[i] + 1){
				result[next] = result[i] + 1;
				qu.push(next);
			}
		}
	}
	cout << result[0] << endl;
	return 0;
}
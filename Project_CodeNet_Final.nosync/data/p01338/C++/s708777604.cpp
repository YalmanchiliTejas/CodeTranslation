#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

int tobit(int x[5])
{
	int ret = 0;
	
}

int main()
{
	int testcase;
	
	scanf("%d", &testcase);
	
	for(int testnum = 0; testnum < testcase; ++testnum) {
		
		int start[5][5];
		bool emp[5][5] = {false};
		
		for(int y = 0; y < 5; ++y) {
			for(int x = 0; x < 5; ++x) {
				scanf("%d", start[x] + y);
				start[x][y] -= 1;
				if(start[x][y] == -1) {
					start[x][y] = 0;
					emp[x][y] = true;
				}
			}
		}
		
		int dp[5][1 << 10] = {0};
		const int point[] = {0, 60, 70, 80};
		
		fill(dp[0], dp[5], -1);
		
		int startbit = 0;
		int startpoint = 0;
		for(int i = 0; i < 5; ++i) {
			startbit |= start[0][i] << (i * 2);
			startpoint += point[start[0][i]];
		}
		dp[0][startbit] = startpoint;
		
		for(int col = 0; col < 4; ++col) {
			
			for(int state = 0; state < (1 << 10); ++state) {
				
				if(dp[col][state] == -1)
					continue;
				
				int statepoint = 0;
				for(int i = 0; i < 5; ++i)
					statepoint += !emp[col][i] * point[(state >> (i * 2)) & 3];
			
				for(int button = 0; button < (1 << 8); ++button) {
					
					int cur[5] = {0};
					int next[5] = {0};
					
					for(int i = 0; i < 5; ++i) {
						cur[i] = (state >> (i * 2)) & 3;
						next[i] = start[col + 1][i];
					}
					
					for(int i = 0; i < 4; ++i) {
						int push = (button >> (i * 2)) & 3;
						next[i] = (next[i] + push) & 3;
						next[i + 1] = (next[i + 1] + push) & 3;
						cur[i] = (cur[i] + push) & 3;
						cur[i + 1] = (cur[i + 1] + push) & 3;
					}
					
					int nextbit = 0;
					int nextpoint = dp[col][state] - statepoint;
					
					for(int i = 0; i < 5; ++i)
						nextbit |= next[i] << (i * 2);
					for(int i = 0; i < 5; ++i) {
						nextpoint += !emp[col][i] * point[cur[i]];
						nextpoint += !emp[col + 1][i] * point[next[i]];
					}
					
					dp[col + 1][nextbit] = max(dp[col + 1][nextbit], nextpoint);
				}
			}
		}
		
		int ans = 0;
		
		for(int i = 0; i < (1 << 10); ++i)
			ans = max(ans, dp[4][i]);
		
		printf("%d\n", ans);
	}
	
	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
/* nullmineralが書きましたが */
/* 責任はまったくとりません */